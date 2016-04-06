import json
import os
from django.contrib.auth.models import User

from backend.models import Problem, Company, Candidate, ProblemFunction, College, Submission
from backend.enums import ProblemSubCategory, ProblemCategory, ProblemDifficulty, LanguageName
from backend.constants import LANGUAGE_FILE_EXTENSION_MAP
from hacktheinterview.settings import PROJECT_ROOT

def cleanData():
	Company.objects.all().delete()
	Candidate.objects.all().delete()
	Problem.objects.all().delete()
	Submission.objects.all().delete()
	User.objects.all().delete()
	ProblemFunction.objects.all().delete()

def masterSeeder():
	candidate = seedCandidate()
	company = candidate.company
	seedAllProblems()


def seedCandidate():
	user = seedUser()
	return Candidate.objects.create(college=seedCollege(), company=seedCompany(), user=user)

def seedUser():
	lastUserId = User.objects.last().id if User.objects.last() else -1
	newUserSuffix = lastUserId + 1

	firstName = "First" + str(newUserSuffix)
	lastName = "Last" + str(newUserSuffix)
	email = firstName + lastName + "@hack.com"

	return User.objects.create_user(email, first_name=firstName, last_name=lastName,
		password="password", email=email)


def seedCompany():
	return Company.objects.create(name='FACEBOOK')


def seedCollege():
	return College.objects.create(name="IIT ROPAR")

# Basically we will seed all the problems in our repo to avoid confusion
def seedAllProblems():
	problemsRootDir = os.path.join(PROJECT_ROOT, "problems")
	directories = os.listdir(problemsRootDir)
	for i in directories:
		problemDirectory = os.path.join(problemsRootDir, i)
		print problemDirectory
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

		languages = [LanguageName.C, LanguageName.CPP, LanguageName.JAVA, LanguageName.PYTHON]

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
