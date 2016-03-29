import os
import datetime
import json
import simplejson
import requests
import random

from rq import Queue
from worker import conn

from django.shortcuts import render_to_response
from django.http import HttpResponse, Http404
# from backend.models import *
from django.views.decorators.csrf import csrf_exempt




from backend.runner import Runner
from backend.enums import LanguageName
from backend.constants import LANGUAGE_FILE_EXTENSION_MAP, HTI_TO_HACKER_EARTH_LANGUAGE_MAP
from backend.utils.source_utils import createFullSourceCode

from hackerearth.api_handlers import HackerEarthAPI
from hackerearth.parameters import RunAPIParameters, SupportedLanguages, CompileAPIParameters
from hacktheinterview.settings import HACKER_EARTH_API_KEY

def editGccCompilerLog(compilerLog, no_of_lines_to_subtract):
	# Refer http://stackoverflow.com/questions/18022124/parsing-gcc-error-log
	lines = compilerLog.split("\n")
	output_log = ""
	for line in lines:
		items = line.split(":")
		if len(items) > 2:
			items[0] = str(int(items[1]) - no_of_lines_to_subtract)
			output_log += ":".join(items)
		else:
			output_log += line
	return output_log

def getHeaderSource(problemId, lang):
	headerSourceFileName = "header." + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	headerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, problemId, headerSourceFileName)
	headerSource = open(headerSourceFileLocation).read()
	return headerSource

def handleCompilationError(result, submission):
	if submission.language in [LanguageName.C, LanguageName.CPP] :
		linesToSubtract = len(getHeaderSource(problem.id, submission.language)) + 2
		compilationErrorLog = editGccCompilerLog(result.compile_status, linesToSubtract)
		# save metadata information in the submission
		submission.status = SubmissionStatus.CE
		submission.originalCompilerLog = result.compile_status
		submission.compilerLog = compilationErrorLog
		submission.save()
	else:
		raise NotImplementedError("Not implemented for other languages")

def getInputData(problemId, isSample=False):
	inputSourceFileName = "input.txt"
	inputSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, problemId, inputSourceFileName)
	inputSource = open(inputSourceFileLocation).read()
	return inputSource


def getOutputData(problemId, isSample=False):
	outputSourceFileName = "output_sample.txt" if isSample else "output.txt"
	outputSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, problemId, outputSourceFileName)
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
		submission.status = SubmissionStatus.WA
		submission.timeUsed = result.time_used
		submission.memoryUsed = result.memory_used
		submission.failedCase = failedIndex
		submission.expected = expected
		submission.obtained = obtained
		submission.save()
	else:
		submission.status = SubmissionStatus.AC
		submission.timeUsed = result.time_used
		submission.memoryUsed = result.memory_used
		submission.save()


def handleRunTimeError(result, submission):
	pass

def handleTimeLimitExceeded(result, submission):
	#expectedOutput = getOutputData(submission.problem.id, submission.isSample)
	obtainedOutput = result.output

	#eLines = expectedOutput.split("\n")
	oLines = obtainedOutput.split("\n")
	failedCase = len(oLines) - 1

def parseHackerEarthResult(result):
	# TODO(Rad), dump result to a logger / analytics
	# Verify whether compile_status is ok or not.
	subission = result.id
	if result['status'] == 'CE':
		handleCompilationError(result, submission)
	elif result['status'] == 'OK':
		handleGeneralSubmission(result, submission)
	elif result['status'] == 'RE':
		handleRunTimeError(result, submission)
	elif result['status'] == 'TLE':
		handleTimeLimitExceeded(result, submission)
	else:
		handleException(result)


@csrf_exempt
def test_url(request):
	payload = request.POST.get('payload', '')
	payload = json.loads(payload)

	print "Request came"
	# q.enqueue(count_words_at_url, 'http://heroku.com')
	return HttpResponse("API Response Received")



def postSubmissionToEngine(submissionId):
	submission = Submission.objects.get(id=submissionId)
	problemId = submission.problem_id
	lang = submission.language
	userSource = submission.source
	fullSourceCode = prepareSourceCode(problemId, lang, userSource)


def prepareSourceCode(problemId, lang, userSource):
	# Validate whether problem id is correct or not
	# Validate language
	headerSourceFileName = "header." + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	headerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, problemId, headerSourceFileName)
	headerSource = open(headerSourceFileLocation).read()

	footerSourceFileName = "footer." + LANGUAGE_FILE_EXTENSION_MAP.get(lang)
	footerSourceFileLocation = os.path.join(PROBLEM_ROOT_DIR, problemId, footerSourceFileName)
	footerSource = open(footerSourceFileLocation).read()

	fullSourceCode = createFullSourceCode(headerSource, userSource, footerSource)
	return fullSourceCode

def getProblemLimits(problemId):
	return {
		'time_limit' : 1,
		'memory_limit': 1024 * 1024,
	}

def postSubmissionToEngine(submissionId):
	submission = Submission.objects.get(id=submissionId)
	userSource = submission.source
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
		program_input=inputSource,
		time_limit=limits['time_limit'],
		memory_limit=limits['memory_limit'],
		async=1,
		id=submission.id,
		callback='http://sheltered-ocean-78784.herokuapp.com/test_url/',
		compressed=0,
	)

	api = HackerEarthAPI(run_params)
	r = api.run()
	print r.__dict__

@csrf_exempt
def create_submission(request):
	user_source_code = "print x"
	problem = Problem.objects.get(id=1)
	language = LanguageName.C_PLUS_PLUS
	candidate = Candidate.objects.get(id=1)
	

	s = Submission.objects.create(
		problem=problem,
		candidate=candidate,
		language=language,
		source=user_source_code,
	)
	postSubmissionToEngine(s)
	return HttpResponse(json.dumps({'submission_id': s.id}), 'application/json')

	# run_id = Submission.objects.count()+1
	# user_id = 1
	# problem = Problem.objects.get(problem_id=int(request.POST["problem_id"]))
	# source_code = request.POST["source_code"]
	# submission_time = datetime.datetime.now()
	# language = request.POST["language"]
	# language = language.upper()
	# status = "QUEUED"
	# compiler_error_log= " "
	# time_taken = -1
	# exit_code = 100000
	# print problem
	# s= Submission(run_id=run_id,user_id=user_id,problem=problem,source_code=source_code,submission_time=submission_time,
	# 	status=status,language=language,compiler_error_log=compiler_error_log,time_taken=time_taken,
	# 	exit_code=exit_code,issubmission=True)
	# s.save()
	# redirect_url = "/submissions/%s" % str(run_id)
	# print redirect_url
	# return HttpResponse(simplejson.dumps({'redirect_url':redirect_url}), 'application/json')


@csrf_exempt
def compile_and_test(request):
	# insert source code
	run_id = Submission.objects.count() +1
	user_id = 1
	problem = Problem.objects.get(problem_id=int(request.POST["problem_id"]))
	source_code = request.POST["source_code"]
	submission_time = datetime.datetime.now()
	language = request.POST["language"]
	language = language.upper()
	status = "QUEUED"
	compiler_error_log= " "
	time_taken = -1
	exit_code = 100000
	s= Submission(run_id=run_id,user_id=user_id,problem=problem,source_code=source_code,submission_time=submission_time,
		status=status,language=language,compiler_error_log=compiler_error_log,time_taken=time_taken,
		exit_code=exit_code,issubmission=False)
	s.save()
	return HttpResponse(simplejson.dumps({'run_id':run_id}), 'application/json')

def get_compilation_status(request):
	run_id = request.GET["run_id"]
	rows = list(Submission.objects.filter(run_id=run_id))

	if len(rows) == 0:
		return HttpResponse('not found')

	row = rows[0]

	return HttpResponse(simplejson.dumps({'status':row.status}), 'application/json')


def get_compilation_result(request):
	run_id = request.GET["run_id"]
	rows = list(Submission.objects.filter(run_id=run_id))

	if len(rows) == 0:
		return HttpResponse('not found')

	row = rows[0]

	submission = dict()

	submission['status'] = row.status
	submission['compilation_log'] = row.compiler_error_log
	submission['unitrun_results'] = list(Submission_unitrun.objects.filter(Submission=row))

	return render_to_response('compilation_results.html', submission)

def submissions(request, offset):
	run_id = int(offset)
	submissions = list(Submission.objects.filter(run_id=run_id))

	if len(submissions) == 0:
		return Http404()

	submission = submissions[0]

	unitruns = list(Submission_unitrun.objects.filter(Submission = submission))

	return render_to_response("submissions.html", { 'submission': submission, 'unitruns': unitruns })

def problem(request,offset):
	problem_no = int(offset)
	rows = list(Problem.objects.filter(problem_id=problem_no))
	if len(rows) == 0 :
		return render_to_response("404.html");
	row = rows[0]
	q = dict()
	q["title"] = row.title
	q["difficulty"] = row.difficulty*100
	q["content"] = row.content
	q["problem_id"] = row.problem_id
	rows = list(Problem_Functions.objects.filter(problem_id=problem_no))
	if len(rows) > 0:
		row = rows[0]
		q["problem_code_c"] = row.c_code
		q["problem_code_cpp"] = row.cpp_code
		q["problem_code_java"] = row.java_code

	return render_to_response("problem.html",{"problem":q})

def home(request):
	type = "LIST"
	return render_to_response("templates/problem_page.html")

	# rows  = list(Problem.objects.filter(types__contains=type))
	# problems = []
	# for row in rows:
	# 	q = dict()
	# 	print row.title
	# 	q["title"] = row.title
	# 	q["difficulty"] = row.difficulty * 100
	# 	q["previewtext"] = row.previewtext
	# 	q["totalsubmission"] = row.totalsubmission
	# 	q["problem_id"] = row.problem_id
	# 	if row.totalsubmission == 0:
	# 		q["accuracy"] = 0
	# 	else:
	# 		q["accuracy"] = ((row.passedsubmissions*100)/row.totalsubmission)
	# 	problems.append(q)

	# return render_to_response("home.html",locals())

def get_problems_by_type(request):
	type = request.GET['type']
	type = "LIST"
	rows  = list(Problem.objects.filter(types__contains=type))
	questions = []
	os.system("sleep 1")
	for row in rows:
		q = dict()
		print row.title
		q["title"] = row.title
		q["difficulty"] = row.difficulty * 100
		q["previewtext"] = row.previewtext
		q["totalsubmission"] = row.totalsubmission

		if row.totalsubmission == 0:
			q["accuracy"] = 0
		else:
			q["accuracy"] = ((row.passedsubmissions*100)/row.totalsubmission)

		questions.append(q)

	return render_to_response("problem_list.html", {"problems":questions})
