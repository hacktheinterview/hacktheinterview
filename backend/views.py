import os
import datetime
import json
import simplejson
import requests
import random

from rq import Queue
from worker import conn

from django.shortcuts import render_to_response
from django.http import HttpResponse, JsonResponse, Http404
from django.views.decorators.csrf import csrf_exempt
from django.template.loader import render_to_string

from backend.runner import Runner
from backend.enums import LanguageName, SubmissionStatus
from backend.constants import LANGUAGE_FILE_EXTENSION_MAP, HTI_TO_HACKER_EARTH_LANGUAGE_MAP, PROBLEM_ROOT_DIR
from backend.utils.source_utils import createFullSourceCode
from backend.models import Problem, Submission, Candidate

from hackerearth.api_handlers import HackerEarthAPI
from hackerearth.result import RunResult
from hackerearth.parameters import RunAPIParameters, SupportedLanguages, CompileAPIParameters
from hacktheinterview.settings import HACKER_EARTH_API_KEY

def editGccCompilerLog(compilerLog, no_of_lines_to_subtract):
	# Refer http://stackoverflow.com/questions/18022124/parsing-gcc-error-log
	# In function `main':\n(.text.startup+0x7c): undefined reference to `Solution::reverseList(ListNode*)'\n error: ld returned 1 exit status\n\n
	print compilerLog
	print no_of_lines_to_subtract
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

def getHeaderSource(problemId, lang):
	headerSourceFileName = "header" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	headerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), headerSourceFileName)
	headerSource = open(headerSourceFileLocation).read()
	return headerSource

def getFooterSource(problemId, lang):
	footerSourceFileName = "footer" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	footerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), footerSourceFileName)
	footerSource = open(footerSourceFileLocation).read()
	return footerSource

def getSkeletonSource(problemId, lang):
	skeletonSourceFileName = "skeleton" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	skeletonSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), skeletonSourceFileName)
	skeletonSource = open(skeletonSourceFileLocation).read()
	return skeletonSource

def getAdminSolutionSource(problemId, lang):
	solutionSourceFileName = "solution" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	solutionSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), solutionSourceFileName)
	solutionSource = open(solutionSourceFileLocation).read()
	return solutionSource

def countLinesInHeaderSource(problemId, lang):
	headerSourceFileName = "header" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	headerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), headerSourceFileName)
	headerLines = sum(1 for line in open(headerSourceFileLocation))
	return headerLines


def editJAVACompilerLog(compilerLog, no_of_lines_to_subtract):
	print compilerLog
	print no_of_lines_to_subtract
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
	if submission.language in [LanguageName.C, LanguageName.CPP]:
		linesToSubtract = countLinesInHeaderSource(submission.problem.id, submission.language) + 1
		print "linesToSubtract :", linesToSubtract
		compilationErrorLog = editGccCompilerLog(result.compile_status, linesToSubtract)
		print "Changed Compiler Log"
		print compilationErrorLog
		# save metadata information in the submission
		submission.status = SubmissionStatus.CE
		submission.originalCompilerErrorLog = result.compile_status
		submission.compilerErrorLog = compilationErrorLog
		submission.save()
	elif submission.language == LanguageName.JAVA:
		linesToSubtract = countLinesInHeaderSource(submission.problem.id, submission.language) + 1
		print "linesToSubtract :", linesToSubtract
		compilationErrorLog = editJAVACompilerLog(result.compile_status, linesToSubtract)
		print "Changed Compiler Log"
		print compilationErrorLog
		# save metadata information in the submission
		submission.status = SubmissionStatus.CE
		submission.originalCompilerErrorLog = result.compile_status
		submission.compilerErrorLog = compilationErrorLog
		submission.save()
	else:
		raise NotImplementedError("Not implemented for other languages")

def getInputData(problemId, isSample=False):
	inputSourceFileName = "input.txt"
	inputSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), inputSourceFileName)
	inputSource = open(inputSourceFileLocation).read()
	return inputSource


def getOutputData(problemId, isSample=False):
	outputSourceFileName = "output_sample.txt" if isSample else "output.txt"
	outputSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), outputSourceFileName)
	outputSource = open(outputSourceFileLocation).read()
	return outputSource

	# PENDING = EnumValue("PENDING", "Pending")
	# CE      = EnumValue("CE", "Compilation Error")
	# AC      = EnumValue("AC", "Correct Answer")
	# WA      = EnumValue("WA", "Wrong Answer")
	# TLE     = EnumValue("TLE", "Time Limit Exceeded")
	# MLE     = EnumValue("MLE", "Memory Limit Exceeded")
	# OTHER   = EnumValue("OTHER", "Reason Not Yet found")

def handleGeneralSubmission(result, submission):
	expectedOutput = getOutputData(submission.problem.id, submission.isSample)
	obtainedOutput = result.output

	eLines = expectedOutput.split("\n")
	oLines = obtainedOutput.split("\n")

	failed = False
	failedIndex = -1
	expectedLine = None
	obtainedLine = None
	for i, (expected, obtained) in enumerate(zip(eLines, oLines)):
		if expected == obtained:
			continue
		else:
			failed=True
			failedIndex = i
			expectedLine = expected
			obtainedLine = obtained
			break

	if failed:
		inputSource = getInputData(submission.problem.id, submission.isSample)
		inputLines = inputSource.split("\n")
		inputLines = inputLines[1:]
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
def handleRunTimeError(result, submission):
	expectedOutput = getOutputData(submission.problem.id, submission.isSample)
	obtainedOutput = result.output

	oLines = obtainedOutput.split("\n")
	failedCase = len(oLines)

	inputSource = getInputData(submission.problem.id, submission.isSample)
	inputLines = inputSource.split("\n")
	inputLines = inputLines[1:]

	submission.status = SubmissionStatus.RTE
	submission.failedCase = failedCase
	submission.testCaseText = inputLines[failedIndex]
	submission.save()

def handleTimeLimitExceeded(result, submission):
	expectedOutput = getOutputData(submission.problem.id, submission.isSample)
	obtainedOutput = result.output

	#eLines = expectedOutput.split("\n")
	oLines = obtainedOutput.split("\n")
	failedCase = len(oLines)

	inputSource = getInputData(submission.problem.id, submission.isSample)
	inputLines = inputSource.split("\n")
	inputLines = inputLines[1:]

	submission.status = SubmissionStatus.TLE
	submission.failedCase = failedCase
	submission.testCaseText = inputLines[failedIndex]
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

	print "Request came"
	print result.__dict__
	parseHackerEarthResult(result)
	return HttpResponse("API Response Received")


def prepareSourceCode(problemId, lang, userSource):
	# Validate whether problem id is correct or not
	# Validate language
	headerSourceFileName = "header" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	headerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), headerSourceFileName)
	headerSource = open(headerSourceFileLocation).read()

	footerSourceFileName = "footer" + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	footerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, str(problemId), footerSourceFileName)
	footerSource = open(footerSourceFileLocation).read()

	fullSourceCode = createFullSourceCode(headerSource, userSource, footerSource)
	return fullSourceCode

def getProblemLimits(problemId):
	return {
		'time_limit' : 1,
		'memory_limit': 1024 * 1024,
	}

def postSubmissionToEngine(submission):
	userSource = submission.source
	problemId = submission.problem.id
	lang = submission.language
	isSample = submission.isSample
	fullSource = prepareSourceCode(problemId, lang, userSource)
	inputText = getInputData(problemId, isSample)

	hackerEarthLanguage = HTI_TO_HACKER_EARTH_LANGUAGE_MAP.get(lang)
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
		callback='https://alvsuvkmtj.localtunnel.me/test_url/',
		#callback='http://sheltered-ocean-78784.herokuapp.com/test_url/',
		compressed=0,
	)

	api = HackerEarthAPI(run_params)
	r = api.run()

@csrf_exempt
def create_submission(request):
	problem_id = request.POST.get('problem_id')
	user_source_code = request.POST.get('source_code')
	language = request.POST.get('language')
	isSample = request.POST.get('isSample')

	problemId = 1
	language = LanguageName.JAVA
	#user_source_code = getAdminSolutionSource(problemId, language)
	problem = Problem.objects.get(id=problemId)
	candidate = Candidate.objects.get(id=1)

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
		htmlContent = render_to_string("templates/submission_status.html",
				{'submissionStatus': submissionStatus})
		pass
	elif submission.status == 'CE':
		submissionStatus['compilerErrorLog'] = submission.compilerErrorLog
		htmlContent = render_to_string("templates/submission_status.html",
				{'submissionStatus': submissionStatus})

	elif submission.status == 'AC':
		htmlContent = render_to_string("templates/submission_status.html",
				{'submissionStatus': submissionStatus})
	elif submission.status == 'WA':
		pass

	submissionStatus['htmlContent'] = htmlContent
	return submissionStatus

def get_submission_status(request):
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
		print problems
	return render_to_response("templates/problem_list.html", {"problems": problems})

def getRecentSubmission(problem_id):
	return None


def problem_page(request, problem_id=1):
	print problem_id
	# Check if problem exists, else return 404
	problem = Problem.objects.get(id=problem_id)
	problem_content_url = 'templates/problem_descriptions/{}.html'.format(problem_id)
	recentSubmission = {
		"language": "Java 8 (oracle-jdk-1.8)",
		"source": getSkeletonSource(problem_id, LanguageName.JAVA)
	}

	return render_to_response("templates/problem_page.html", {
		"problem": problem,
		"problem_content_url":problem_content_url,
		"recentSubmission": recentSubmission
	})
