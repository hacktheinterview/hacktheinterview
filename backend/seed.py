import json
import os
from django.contrib.auth.models import User

from backend.models import Problem, Company, Candidate
from backend.enums import ProblemSubCategory, ProblemCategory, ProblemDifficulty
from backend.constants import LANGUAGE_FILE_EXTENSION_MAP
from hacktheinterview.settings import PROJECT_ROOT

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
	# def createProblemFromDirectory(problemDirectory):
	# 	# Read metadata.json
	# listAllTheDirectories under problems
	# read metadata.json, create Problem objects
	problemsRootDir = os.path.join(PROJECT_ROOT, "problems")
	directories = os.listdir(problemsRootDir)
	for i in directories:
		problemDirectory = os.path.join(problemsRootDir, i)
		print problemDirectory
		problem_id = int(i)
		metadataFile = os.path.join(problemDirectory, "metadata.json")
		metadataJson = open(metadataFile).read()
		d = json.loads(metadataJson)
		name = d['name']
		category = d['category']
		ProblemCategory.validateValue(category)
		difficulty = d['difficulty']
		ProblemDifficulty.validateValue(difficulty)

		for company in d['companies']:
			Company.objects.get_or_create(
				name=company
			)

		companies = Company.objects.filter(name__in=d['companies'])
		problem = Problem.objects.update_or_create(
			name=name, defaults={
				'category': category,
				'companies': companies,
				'difficulty': difficulty,
				'name': name
			}
		)

		languages = [LanguageName.C, LanguageName.C_PLUS_PLUS]
		for lang in languages:
			langExtension = LANGUAGE_FILE_EXTENSION_MAP.get(lang)
			
			headerFileName = "header." + langExtension
			headerFileLocation = os.path.join(problemDirectory, headerFileName)
			headerSource = open(headerFileLocation).read()

			footerFileName = "footer." + langExtension
			footerFileLocation = os.path.join(problemDirectory, footerFileName)
			footerSource = open(footerFileLocation).read()

			skeletonFileName = "skeleton." + langExtension
			skeletonFileLocation = os.path.join(problemDirectory, skeletonFileName)
			skeletonSource = open(skeletonFileLocation).read()

			read headerFile, read footer file, read skeleton file
			
			ProblemFunction.objects.create(
				language=lang,
				problem=problem,
				userSkeleton=skeletonSource,
				header=headerSource,
				footer=footerSource
			)
