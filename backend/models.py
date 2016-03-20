from django.contrib.auth.models import User
from django.db import models
from backend.enums import ProblemCategory, ProblemDifficulty, LanguageName, TestCaseSubmissionStatus


class Company(models.Model):
	name = models.CharField(max_length=255)

class Problem(models.Model):
	name = models.CharField(max_length=255)
	category = models.CharField(max_length=255, choices=ProblemCategory.choices())
	difficulty = models.CharField(max_length=255, choices=ProblemDifficulty.choices())

	companies = models.ManyToManyField(Company, related_name='problems')

	@property
	def url(self):
		return self.name.lower().strip().replace(" ", "-")


class TestCase(models.Model):
	"""
	"""
	problem = models.ForeignKey(Problem, related_name="testCases")


class Candidate(models.Model):
	college = models.CharField(max_length=255)
	user = models.OneToOneField(User, related_name="candidate", on_delete=models.CASCADE)

class Submission(models.Model):
	"""
	Stores a submission made by candidate
	"""
	problem = models.ForeignKey(Problem, related_name="submissions")
	candidate = models.ForeignKey(Candidate, related_name="submissions")
	language = models.CharField(max_length=255, choices=LanguageName.choices())
	source = models.TextField(verbose_name='source code')


class TestCaseSubmission(models.Model):
	testCase = models.ForeignKey(TestCase, related_name="testCaseSubmissions")
	submission = models.ForeignKey(Submission, related_name="submissions")
	status = models.CharField(max_length=255, choices=TestCaseSubmissionStatus.choices())
	submissionDetail = models.TextField(verbose_name="")


# Saves the draft for particular problem for an user
class Draft(models.Model):
	problem = models.ForeignKey(Problem, related_name="draft")
	candidate = models.ForeignKey(Candidate, related_name="drafts")
	language = models.CharField(max_length=255, choices=LanguageName.choices())
	sourceCode = models.TextField()
	class Meta:
		unique_together = ('problem', 'candidate')


# Driver functions for the problems
#      
# Part1: cHeaders
#     #include <stdio.h>
#     #include <string.h>
#     struct node * {
#	  blah 
#     }
# 
# Part2: cUserSkeleton
#      skeleton for user
#      void add(int a, int b) {
#
#      }
#
# Part3: cRunnerFunction
# int main() {
#	   call user function and make sure result is right
# }

class ProblemFunctions(models.Model):
	problem = models.ForeignKey(Problem, related_name="problemFunctions")
	language = models.CharField(max_length=255, choices=LanguageName.choices())
	
	headers = models.TextField()
	userSkeleton = models.TextField()
	runnerFunction = models.TextField()

	cPlusHeaders = models.TextField()
	cPlusUserSkeleton = models.TextField()
	cPlusRunnerFunction = models.TextField()

# class Submission(models.Model):
# 	run_id = models.IntegerField(primary_key=True)
# 	user_id = models.IntegerField()
# 	problem = models.ForeignKey(Problem)
# 	source_code = models.TextField()
# 	submission_time = models.DateTimeField()
# 	status = models.CharField(max_length=50)
# 	language = models.CharField(max_length=20)
# 	issubmission = models.BooleanField(default=False)
# 	compiler_error_log = models.TextField()

# 	# Maximum time taken
# 	time_taken = models.IntegerField()

# 	exit_code = models.IntegerField()

# 	class Meta:
# 		db_table = "Submission"

# 	def __unicode__(self):
# 		return "User_Id: %d \n run_id %d " % (self.user_id, self.run_id)


# class Submission_unitrun(models.Model):
# 	Submission = models.ForeignKey(Submission)
# 	time_taken = models.IntegerField()
# 	exit_code = models.IntegerField()
# 	output = models.TextField()
# 	result = models.CharField(max_length=100)
# 	testcase_no = models.IntegerField()

# 	class Meta:
# 		db_table = "Submission_unitrun"

# 	def __unicode__(self):
# 		return "Submission Id:%d, Testcase_no %d" % (self.Submission.run_id, self.testcase_no)


# class Problem_Functions(models.Model):
# 	problem = models.ForeignKey(Problem)
# 	c_code = models.TextField()
# 	c_main_code = models.TextField()
# 	cpp_code = models.TextField()
# 	cpp_main_code = models.TextField()
# 	java_code = models.TextField()
# 	java_main_code = models.TextField()

# 	class Meta:
# 		db_table = "Problem_Functions"

# 	def __unicode__(self):
# 		return "%d->%s" % (self.problem.problem_id, self.problem.title)
