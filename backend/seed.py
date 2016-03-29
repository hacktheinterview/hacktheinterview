from django.contrib.auth.models import User

from backend.models import Problem, Company, ProblemFunctions, Candidate
from backend.enums import ProblemSubCategory, ProblemCategory, \
	ProblemDifficulty, LanguageType

def seedCompany():
	return Company.objects.create(name='FACEBOOK')

def masterSeeder():
	candidate = seedCandidate()
	company = seedCompany()
	problem = seedBasicProblem(companies=[company])
	seedProblemFunction(problem)

def seedUser():
	lastUserId = User.objects.last().id if User.objects.last() else -1
	newUserSuffix = lastUserId + 1

	firstName = "First" + str(newUserSuffix)
	lastName = "Last" + str(newUserSuffix)
	email = firstName + lastName + "@hack.com"

	return User.objects.create_user(email, first_name=firstName, last_name=lastName,
		password="password", email=email)

def seedCandidate():
	user = seedUser()
	return Candidate.objects.create(college="IIT Ropar")

def problemFunctionForAddTwoNumbers():
	cHeaders = ""
	cUserSkeleton = open("seed_fixtures/user_skeleton_add_two_nums.txt").read()
	cRunnerFunction = ""
	return cHeaders, cUserSkeleton, cRunnerFunction


def seedProblemFunction(problem, cHeaders=None, 
						cUserSkeleton=None, cRunnerFunction=None):
	cHeaders, cUserSkeleton, cRunnerFunction = problemFunctionForAddTwoNumbers()

	ProblemFunctions.objects.create(cHeaders=cHeaders,
		cUserSkeleton=cUserSkeleton, cRunnerFunction=cRunnerFunction)


def seedBasicProblem(name="Addition of two numbers",
				category=ProblemCategory.ARRAY,
				difficulty=ProblemDifficulty.EASY,
				companies=None):
	return Problem.objects.create(name=name, category=category, 
				difficulty=difficulty, companies=companies)