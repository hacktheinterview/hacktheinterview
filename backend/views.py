import os
import re
import json

from django.shortcuts import render_to_response
from django.http import HttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt
from django.template.loader import render_to_string

from backend.enums import Language, SubmissionStatus, SourceType
from backend.constants import LANGUAGE_FILE_EXTENSION_MAP, HTI_TO_HACKER_EARTH_LANGUAGE_MAP, PROBLEM_ROOT_DIR
from backend.models import Problem, Submission, Candidate

from hackerearth.api_handlers import HackerEarthAPI
from hackerearth.result import RunResult
from hackerearth.parameters import RunAPIParameters
from hacktheinterview.settings import HACKER_EARTH_API_KEY


def getSource(problemId, sourceType, language):
	extension = LANGUAGE_FILE_EXTENSION_MAP.get(language, '')
	if sourceType in [SourceType.INPUT, SourceType.INPUT_SAMPLE, SourceType.OUTPUT, SourceType.OUTPUT_SAMPLE]:
		extension = ".txt"
	sourceFileName = sourceType + extension
	sourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), sourceFileName)
	source = open(sourceFileLocation).read()
	return source


def getSourceLineCount(problemId, sourceType, language):
	extension = LANGUAGE_FILE_EXTENSION_MAP.get(language)
	if sourceType in [SourceType.INPUT, SourceType.INPUT_SAMPLE, SourceType.OUTPUT, SourceType.OUTPUT_SAMPLE]:
		extension = ".txt"
	sourceFileName = sourceType + extension
	sourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), sourceFileName)
	return sum(1 for line in open(sourceFileLocation))


def editPythonErrorLog(errorLog, no_of_lines_to_subtract):
	def repl(m):
		return "{}File {}, line {}".format(m.group(1), m.group(2), str(int(m.group(3)) - no_of_lines_to_subtract))

	return re.sub("(.*)File (.*), line (\d+)", repl, errorLog, flags=re.MULTILINE)


def editJavaStackTrace(javaExceptionLog, no_of_lines_to_subtract):
	def repl(m):
		return "(Solution.java:{})".format(str(int(m.group(1)) - no_of_lines_to_subtract))

	return re.sub("\(Solution\.java:(\d+)\)", repl, javaExceptionLog, flags=re.MULTILINE)


def editGccCompilerLog(compilerLog, no_of_lines_to_subtract):
	# Refer http://stackoverflow.com/questions/18022124/parsing-gcc-error-log
	# In function `main':\n(.text.startup+0x7c): undefined reference to `Solution::reverseList(ListNode*)'\n error: ld returned 1 exit status\n\n
	print(compilerLog)
	print(no_of_lines_to_subtract)
	lines = compilerLog.split("\n")
	output_log = ""
	for line in lines:
		items = line.split(":")
		if len(items) >= 4 and ("error" in line or "warning" in line):
			items[0] = str(int(items[0]) - no_of_lines_to_subtract)
			output_log += ":".join(items) + "\n"
		else:
			output_log += line

	return output_log


def editJAVACompilerLog(compilerLog, no_of_lines_to_subtract):
	print(compilerLog)
	print(no_of_lines_to_subtract)
	lines = compilerLog.split("\n")
	output_log = ""
	for line in lines:
		items = line.split(":")
		if len(items) >= 2 and ("error" in line):
			items[0] = str(int(items[0]) - no_of_lines_to_subtract)
			output_log += ":".join(items) + "\n"
		else:
			output_log += line

	return output_log


def handleCompilationError(result, submission):
	if submission.language not in [Language.C, Language.CPP, Language.JAVA, Language.PYTHON]:
		raise NotImplementedError("Not implemented for other languages")

	linesToSubtract = getSourceLineCount(submission.problem.id, SourceType.HEADER, submission.language) + 1
	print("linesToSubtract :{0}".format(linesToSubtract))
	d = {
		Language.C: editGccCompilerLog,
		Language.CPP: editGccCompilerLog,
		Language.JAVA: editJAVACompilerLog,
		Language.PYTHON: editPythonErrorLog
	}
	compilationErrorLog = d[submission.language](result.compile_status, linesToSubtract)
	print("Changed Compiler Log")
	print(compilationErrorLog)
	submission.status = SubmissionStatus.CE
	submission.originalCompilerErrorLog = result.compile_status
	submission.compilerErrorLog = compilationErrorLog
	submission.save()


def handleGeneralSubmission(result, submission):
	sourceType = SourceType.OUTPUT_SAMPLE if submission.isSample else SourceType.OUTPUT
	expectedOutput = getSource(submission.problem.id, sourceType, None)

	obtainedOutput = result.output

	eLines = expectedOutput.split("\n")
	oLines = obtainedOutput.split("\n")

	failed = False
	failedIndex = 0
	expectedLine = None
	obtainedLine = None
	for i, (expected, obtained) in enumerate(zip(eLines, oLines)):
		if expected == obtained:
			continue
		else:
			failed = True
			failedIndex = i + 1
			expectedLine = expected
			obtainedLine = obtained
			break

	if failed:
		sourceType = SourceType.INPUT_SAMPLE if submission.isSample else SourceType.INPUT
		inputSource = getSource(submission.problem.id, sourceType, None)
		inputLines = inputSource.split("\n")
		submission.status = SubmissionStatus.WA
		submission.timeUsed = result.time_used
		submission.memoryUsed = result.memory_used
		submission.failedCase = failedIndex
		submission.testCaseText = inputLines[failedIndex]
		submission.expected = expected
		submission.obtained = obtained
		submission.save()
	else:
		submission.status = SubmissionStatus.AC
		submission.timeUsed = result.time_used
		submission.memoryUsed = result.memory_used
		submission.save()


# May be show wrong answer while doing the comparison and if comparison is ok, then show RTE?
# TODO(Rad). This will throw error when users print more than #testcases
# Handle that condition.
# TODO(Rad) Front end expose more information for Run time Error
def handleRunTimeError(result, submission):
	sourceType = SourceType.OUTPUT_SAMPLE if submission.isSample else SourceType.OUTPUT
	expectedOutput = getSource(submission.problem.id, sourceType, None)

	obtainedOutput = result.output

	oLines = obtainedOutput.split("\n")
	failedCase = len(oLines)

	sourceType = SourceType.INPUT_SAMPLE if submission.isSample else SourceType.INPUT
	inputSource = getSource(submission.problem.id, sourceType, None)
	inputLines = inputSource.split("\n")
	inputLines = inputLines[1:]

	submission.status = SubmissionStatus.RTE
	submission.failedCase = failedCase
	submission.testCaseText = inputLines[failedCase]
	# status_detail has signal info like SIGFPE, SIGSEGV etc..
	submission.statusDetail = result.status_detail

	if submission.language == Language.JAVA:
		linesToSubtract = getSourceLineCount(submission.problem.id, SourceType.HEADER, submission.language) + 1
		stderr = editJavaStackTrace(result.stderr, linesToSubtract)

	submission.stderr = result.stderr
	submission.save()


def handleTimeLimitExceeded(result, submission):
	sourceType = SourceType.OUTPUT_SAMPLE if submission.isSample else SourceType.OUTPUT
	expectedOutput = getSource(submission.problem.id, sourceType, None)

	obtainedOutput = result.output

	# eLines = expectedOutput.split("\n")
	oLines = obtainedOutput.split("\n")
	failedCase = len(oLines)

	sourceType = SourceType.INPUT_SAMPLE if submission.isSample else SourceType.INPUT
	inputSource = getSource(submission.problem.id, sourceType, None)
	inputLines = inputSource.split("\n")
	inputLines = inputLines[1:]

	submission.status = SubmissionStatus.TLE
	submission.failedCase = failedCase
	submission.testCaseText = inputLines[failedCase]
	submission.save()


def handleException(result):
	raise NotImplementedError("We don't know what to do here. No clue.")


def parseHackerEarthResult(result):
	# TODO(Rad), dump result to a logger / analytics
	# Verify whether compile_status is ok or not.
	submission = Submission.objects.get(id=result.id)

	if result.status == 'CE':
		handleCompilationError(result, submission)
	elif result.status == 'AC':
		handleGeneralSubmission(result, submission)
	elif result.status == 'RE':
		handleRunTimeError(result, submission)
	elif result.status == 'TLE':
		handleTimeLimitExceeded(result, submission)
	else:
		handleException(result)


@csrf_exempt
def test_url(request):
	payload = request.POST.get('payload', '')
	result = RunResult(payload)

	print("Request came")
	print(result.__dict__)
	parseHackerEarthResult(result)
	return HttpResponse("API Response Received")


def getProblemLimits(problemId):
	return {
		'time_limit': 1,
		'memory_limit': 1024 * 1024,
	}


def postSubmissionToEngine(submission):
	userSource = submission.source
	problemId = submission.problem.id
	language = submission.language
	fullSource = getSource(problemId, SourceType.HEADER, language) + "\n" + userSource + "\n" + getSource(problemId, SourceType.FOOTER, language)
	sourceType = SourceType.INPUT_SAMPLE if submission.isSample else SourceType.INPUT
	inputText = getSource(submission.problem.id, sourceType, None)

	hackerEarthLanguage = HTI_TO_HACKER_EARTH_LANGUAGE_MAP.get(language)
	limits = getProblemLimits(problemId)

	run_params = RunAPIParameters(
		client_secret=HACKER_EARTH_API_KEY,
		source=fullSource,
		lang=hackerEarthLanguage,
		program_input=inputText,
		time_limit=limits['time_limit'],
		memory_limit=limits['memory_limit'],
		async=1,
		id=submission.id,
		callback='https://qakptzvpmk.localtunnel.me/test_url/',
		compressed=0,
	)

	api = HackerEarthAPI(run_params)
	r = api.run()


@csrf_exempt
def createSubmission(request):
	problem_id = int(request.POST.get('problem_id'))
	user_source_code = request.POST.get('source_code')
	language = request.POST.get('language')
	isSample = request.POST.get('isSample')

	language = Language.PYTHON

	#user_source_code = getAdminSolutionSource(problemId, language)
	problem = Problem.objects.get(id=problem_id)
	candidate = Candidate.objects.first()

	s = Submission.objects.create(
		problem=problem,
		candidate=candidate,
		language=language,
		source=user_source_code,
		status=SubmissionStatus.QUEUED,
	)
	postSubmissionToEngine(s)
	return HttpResponse(json.dumps({'submission_id': s.id}), 'application/json')


def prepareSubmissionStatus(submission_id):
	submission = Submission.objects.get(id=submission_id)
	submissionStatus = {}
	submissionStatus['status'] = submission.status
	htmlContent = None

	if submission.status == 'QE':
		htmlContent = render_to_string("templates/submission_status.html", {'submissionStatus': submissionStatus})
	elif submission.status == 'CE':
		submissionStatus['compilerErrorLog'] = submission.compilerErrorLog
		htmlContent = render_to_string("templates/submission_status.html", {'submissionStatus': submissionStatus})
	elif submission.status == 'AC':
		htmlContent = render_to_string("templates/submission_status.html", {'submissionStatus': submissionStatus})
	elif submission.status == 'TLE':
		submissionStatus['inputTestCaseContent'] = printInputTestCase(submission.problem.id, submission.failedCase,
		                                                              submission.isSample)
		htmlContent = render_to_string("templates/submission_status.html", {'submissionStatus': submissionStatus})
	elif submission.status == 'RTE':
		submissionStatus['inputTestCaseContent'] = printInputTestCase(submission.problem.id, submission.failedCase,
		                                                              submission.isSample)
		htmlContent = render_to_string("templates/submission_status.html", {'submissionStatus': submissionStatus})
	elif submission.status == 'WA':
		submissionStatus['inputTestCaseContent'] = printInputTestCase(submission.problem.id, submission.failedCase,
		                                                              submission.isSample)
		submissionStatus['expectedOutputTestCaseContent'] = submission.expected
		submissionStatus['obtainedOutputTestCaseContent'] = submission.obtained
		htmlContent = render_to_string("templates/submission_status.html", {'submissionStatus': submissionStatus})

	submissionStatus['htmlContent'] = htmlContent
	return submissionStatus


def printExpectedOutputTestCaseLinkedList(problem_id, testCaseNum, isSample):
	sourceType = SourceType.OUTPUT_SAMPLE if isSample else SourceType.OUTPUT
	outputSource = getSource(problem_id, sourceType, None)

	outputLines = outputSource.split("\n")
	failedLine = outputLines[testCaseNum - 1]
	return failedLine


def inputLineToLinkedList(failedInputLine):
	inputItems = [int(x) for x in failedInputLine.split(" ")]
	numNodes = inputItems[0]
	nodes = inputItems[1:]
	displayMsg = ""

	for i in range(numNodes):
		if i == numNodes - 1:
			displayMsg += "{}".format(nodes[i])
		else:
			displayMsg += "{} -> ".format(nodes[i])
	if displayMsg == "":
		displayMsg = "Empty Linked List"
	return displayMsg


def inputLineToTwoLinkedLists(failedInputLine):
	inputItems = [int(x) for x in failedInputLine.split(" ")]
	numNodes1 = inputItems[0]
	nodes1 = inputItems[1:(numNodes1 + 1)]
	numNodes2 = inputItems[numNodes1 + 1]
	nodes2 = inputItems[numNodes1 + 2:]
	displayMsg = ""

	displayMsg1 = "List 1 => "
	for i in range(numNodes1):
		if i == numNodes1 - 1:
			displayMsg1 += "{}".format(nodes1[i])
		else:
			displayMsg1 += "{} -> ".format(nodes1[i])
	if displayMsg1 == "":
		displayMsg1 = "List 1 => Empty. "

	displayMsg2 = "List 2 => "
	for i in range(numNodes2):
		if i == numNodes2 - 1:
			displayMsg2 += "{}".format(nodes2[i])
		else:
			displayMsg2 += "{} -> ".format(nodes2[i])

	if displayMsg2 == "":
		displayMsg2 = "List 2 => Empty. "

	displayMsg = displayMsg1 + "\n" + displayMsg2
	return displayMsg

def inputLineToLinkedListAndN(failedInputLine):
	inputItems = [int(x) for x in failedInputLine.split(" ")]
	numNodes = inputItems[0]
	N = inputItems[-1]
	nodes = inputItems[1:-1]
	displayMsg = ""

	for i in range(numNodes):
		if i == numNodes - 1:
			displayMsg += "{}".format(nodes[i])
		else:
			displayMsg += "{} -> ".format(nodes[i])

	if displayMsg == "":
		displayMsg = "Empty Linked List, N = {}".format(N)
	else:
		displayMsg = "LinkedList: {}, N = {}".format(displayMsg, N)
	return displayMsg

def printInputTestCase(problem_id, testCaseNum, isSample):
	printableContent = None
	# TODO(Rad) Come up with a way to define input/output file format

	if problem_id in [1, 3, 4, 5, 7, 8, 9, 11]:
		inputSource = getSource(problem_id, SourceType.INPUT, None)
		inputLines = inputSource.split("\n")
		inputLines = inputLines[1:]

		failedInputLine = inputLines[testCaseNum - 1]
		printableContent = inputLineToLinkedList(failedInputLine)

	elif problem_id in [6, 13, 14, 15]:
		inputSource = getSource(problem_id, SourceType.INPUT, None)
		inputLines = inputSource.split("\n")
		inputLines = inputLines[1:]

		failedInputLine = inputLines[testCaseNum - 1]
		printableContent = inputLineToLinkedListAndN(failedInputLine)

	elif problem_id in [2, 10, 12]:
		inputSource = getSource(problem_id, SourceType.INPUT, None)
		print(inputSource)
		inputLines = inputSource.split("\n")
		inputLines = inputLines[1:]

		failedInputLine = inputLines[testCaseNum - 1]
		print(failedInputLine)
		printableContent = inputLineToTwoLinkedLists(failedInputLine)

	return printableContent


def getSubmissionStatus(request):
	submission_id = request.GET.get('submission_id')
	if not Submission.objects.filter(id=submission_id).exists():
		return HttpResponse("Error baby")

	submissionStatus = prepareSubmissionStatus(submission_id)
	return JsonResponse({
		'status': submissionStatus['status'],
		'htmlContent': submissionStatus['htmlContent']
	})


def home(request):
	allProblems = Problem.objects.all()
	problems = []
	for problem in allProblems:
		tmpProblem = {
			'difficulty': problem.difficulty,
			'title': problem.title,
			'id': problem.id
		}
		problems.append(tmpProblem)
		print(problems)
	return render_to_response("templates/problem_list.html", {"problems": problems})


def getRecentSubmission(problem_id):
	return None


def problemPage(request, problem_id=1):
	print(problem_id)
	# Check if problem exists, else return 404
	problem = Problem.objects.get(id=problem_id)
	problemContentUrl = 'templates/problem_descriptions/{}.html'.format(problem_id)
	recentSubmission = {
		"language": "C (gcc-4.8)",
		"source": getSource(problem_id, SourceType.SKELETON, Language.PYTHON)
	}
	return render_to_response("templates/problem_page.html", {
		"problem": problem,
		"problem_content_url": problemContentUrl,
		"recentSubmission": recentSubmission
	})
