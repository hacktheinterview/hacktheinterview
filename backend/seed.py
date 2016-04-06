import json
import os

from django.contrib.auth.models import User
from django.apps import apps

from backend.models import Problem, Company, Candidate, ProblemFunction, College
from backend.enums import ProblemCategory, ProblemDifficulty, Language
from backend.constants import LANGUAGE_FILE_EXTENSION_MAP
from hacktheinterview.settings import PROJECT_ROOT

COLLEGE_LIST = ["IIT ROPAR"]


def cleanData():
	print("Cleaning Data")
	User.objects.all().delete()
	app = apps.get_app_config('backend')
	for model in app.get_models():
		model.objects.all().delete()


def seedUser(id):
	firstName = "First"
	lastName = "Last" + str(id)
	email = firstName + lastName + "@hack.com"

	return User.objects.create_user(email, first_name=firstName, last_name=lastName, password="password", email=email)


def seedCandidate(id):
	user = seedUser(id)
	college = College.objects.get(name=COLLEGE_LIST[(id % College.objects.count())])
	return Candidate.objects.create(college=college, company=seedCompany(), user=user)


def seedHackTheInterview(numCandidates=1, numCollege=1):
	cleanData()
	for i in range(numCollege):
		seedCollege(i)
	for i in range(numCandidates):
		seedCandidate(i)
	seedAllProblems()


def seedCompany():
	return Company.objects.create(name='FACEBOOK')


def seedCollege(id):
	return College.objects.create(name=COLLEGE_LIST[id])


# Basically we will seed all the problems in our repo to avoid confusion
def seedAllProblems():
	problemsRootDir = os.path.join(PROJECT_ROOT, "problems")
	directories = os.listdir(problemsRootDir)
	for i in directories:
		problemDirectory = os.path.join(problemsRootDir, i)
		problem_id = int(i)
		metadataFile = os.path.join(problemDirectory, "metadata.json")
		d = {}
		with open(metadataFile) as data_file:
			d = json.load(data_file)

		name = d['name']
		category = d['category']
		ProblemCategory.validateValue(category)
		difficulty = d['difficulty']
		ProblemDifficulty.validateValue(difficulty)

		for company in d['companies']:
			Company.objects.get_or_create(name=company)
		timeLimit = int(d['timeLimit'])
		memoryLimit = int(d['memoryLimit'])

		companies = Company.objects.filter(name__in=d['companies'])

		if Problem.objects.filter(id=problem_id).exists():
			problem = Problem.objects.get(id=problem_id)
			problem.companies = companies
			problem.difficulty = difficulty
			problem.name = name
			problem.timeLimit = timeLimit
			problem.memoryLimit = memoryLimit
			problem.save()
		else:
			problem = Problem.objects.create(
				id=problem_id,
				title=name,
				category=category,
				difficulty=difficulty,
				timeLimit=timeLimit,
				memoryLimit=memoryLimit)

			for company in companies:
				problem.companies.add(company)

		languages = [Language.C, Language.CPP, Language.JAVA, Language.PYTHON]

		for lang in languages:
			langExtension = LANGUAGE_FILE_EXTENSION_MAP.get(lang)
			headerFileName = "header" + langExtension
			headerFileLocation = os.path.join(problemDirectory, headerFileName)
			headerSource = open(headerFileLocation).read()

			footerFileName = "footer" + langExtension
			footerFileLocation = os.path.join(problemDirectory, footerFileName)
			footerSource = open(footerFileLocation).read()

			skeletonFileName = "skeleton" + langExtension
			skeletonFileLocation = os.path.join(problemDirectory, skeletonFileName)
			skeletonSource = open(skeletonFileLocation).read()

			ProblemFunction.objects.create(
				language=lang,
				problem=problem,
				skeleton=skeletonSource,
				header=headerSource,
				footer=footerSource
			)
