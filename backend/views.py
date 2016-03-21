# Create your views here.
import os
import datetime
import json

import simplejson
import requests

from django.shortcuts import render_to_response
from django.http import HttpResponse, Http404
# from backend.models import *
from django.views.decorators.csrf import csrf_exempt

from rq import Queue
from worker import conn

from backend.runner import Runner

q = Queue(connection=conn)

runner = Runner()


@csrf_exempt
def test_url(request):
	payload = request.POST.get('payload', '')
	payload = json.loads(payload)
	print payload

	print "Request came"
	# q.enqueue(count_words_at_url, 'http://heroku.com')
	return HttpResponse("API Response Received")


def count_words_at_url(url):
	print "Counting words for task"
	print runner.submit("print('42')", 'python')
	# resp = requests.get(url)
	# print len(resp.text.split())
	# return len(resp.text.split())

def getmysubmissions(request):
	user_id = 1
	submissions = Submission.objects.filter(user_id=user_id,issubmission=True).order_by('-submission_time')
	print submissions
	return render_to_response("mysubmissions.html",locals())


@csrf_exempt
def submit(request):
	run_id = Submission.objects.count()+1
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
	print problem
	s= Submission(run_id=run_id,user_id=user_id,problem=problem,source_code=source_code,submission_time=submission_time,
		status=status,language=language,compiler_error_log=compiler_error_log,time_taken=time_taken,
		exit_code=exit_code,issubmission=True)
	s.save()
	redirect_url = "/submissions/%s" % str(run_id)
	print redirect_url
	return HttpResponse(simplejson.dumps({'redirect_url':redirect_url}), 'application/json')


@csrf_exempt
def compile_and_test(request):
	# insert source code
	run_id = Submission.objects.count()+1
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

	return render_to_response("problem_list.html",{"problems":questions})
