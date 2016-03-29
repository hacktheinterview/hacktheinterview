from django.contrib.auth.models import User
from django.db import models
from django.db.models.signals import post_save
from django.dispatch import receiver

from backend.enums import ProblemCategory, ProblemDifficulty, LanguageName, SubmissionStatus

class Company(models.Model):
	name = models.CharField(max_length=255, null=False)

	def __unicode__(self):
		return self.name

class College(models.Model):
	name = models.CharField(max_length=255, null=False)

	def __unicode__(self):
		return self.name

class NoDeleteQuerySet(models.QuerySet):
	def delete(self, *args, **kwargs):
		print "Dont delete problems :-("
		pass

class NoDeleteManager(models.Manager):
	def get_query_set(self):
		return NoDeleteQuerySet(self.model, using=self._db)

class Problem(models.Model):
	id = models.IntegerField(primary_key=True)

	name = models.CharField(max_length=255)
	category = models.CharField(max_length=255, choices=ProblemCategory.choices())
	difficulty = models.CharField(max_length=255, choices=ProblemDifficulty.choices())

	companies = models.ManyToManyField(Company, related_name='problems')
	timeLimit = models.PositiveIntegerField(verbose_name="TimeLimit", null=False, default=1)
	memoryLimit = models.PositiveIntegerField(verbose_name="Memory limit in KB", null=False, default=256*1024)

	def __unicode__(self):
		return "[{}: {}]".format(self.name, self.difficulty)

	@property
	def url(self):
		return self.name.lower().strip().replace(" ", "-")


class TestCase(models.Model):
	"""
	"""
	problem = models.ForeignKey(Problem, related_name="testCases")


class Candidate(models.Model):
	college = models.ForeignKey(College, related_name="candidates", default=None, null=True)
	company = models.ForeignKey(Company, related_name="candidates", default=None, null=True)
	# TODO(Aayush), do we need cascade?
	user = models.OneToOneField(User, related_name="candidate", on_delete=models.CASCADE)

class Submission(models.Model):
	"""
	Stores a submission made by candidate
	"""
	problem   = models.ForeignKey(Problem, related_name="submissions")
	candidate = models.ForeignKey(Candidate, related_name="submissions")
	language  = models.CharField(max_length=255, choices=LanguageName.choices())
	source    = models.TextField(verbose_name='source code')
	isSample  = models.BooleanField(verbose_name='Compile and run sample tests or not', default=False)
	status    = models.CharField(max_length=255,
					choices=SubmissionStatus.choices(), default=SubmissionStatus.PENDING, null=True)

	originalCompilerLog = models.TextField(default=None, null=True, verbose_name="Compiler log returned from hacker earth api")
	compilerLog = models.TextField(default=None, null=True, verbose_name="Compiler log lines modified by our util function")

	timeUsed = models.DecimalField(default=0.00, null=True, max_digits=2, decimal_places=2, verbose_name="Time taken by the program")
	memoryUsed = models.PositiveIntegerField(default=0, null=True, verbose_name="Memory used by the program in kilo bytes")

	failedCase = models.PositiveIntegerField(default=None, null=True, verbose_name="Test Case # failed because of wrong answer")
	expected = models.TextField(default=None, null=True, verbose_name="Expected outcome for failed test case")
	obtained = models.TextField(default=None, null=True, verbose_name="Obtained outcome for failed test case")

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

class ProblemFunction(models.Model):
	language = models.CharField(max_length=255, choices=LanguageName.choices())
	problem = models.ForeignKey(Problem, related_name="problemFunctions")
	header = models.TextField()
	skeleton = models.TextField()
	footer = models.TextField()

	class Meta:
		unique_together = (('problem', 'language',),)

	def __unicode__(self):
		return "{}: {}".format(self.language, self.problem.name)

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
