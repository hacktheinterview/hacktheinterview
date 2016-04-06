from __future__ import  absolute_import

from django.contrib.auth.models import User
from django.db import models

from backend.enums import ProblemCategory, ProblemDifficulty, Language, SubmissionStatus


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
		print("Dont delete problems :-(")


class NoDeleteManager(models.Manager):
	def get_query_set(self):
		return NoDeleteQuerySet(self.model, using=self._db)


class Problem(models.Model):
	id = models.IntegerField(primary_key=True)

	title = models.CharField(max_length=255)
	category = models.CharField(max_length=255, choices=ProblemCategory.choices())
	difficulty = models.CharField(max_length=255, choices=ProblemDifficulty.choices())

	companies = models.ManyToManyField(Company, related_name='problems')
	timeLimit = models.PositiveIntegerField(verbose_name="TimeLimit", null=False, default=1)
	memoryLimit = models.PositiveIntegerField(verbose_name="Memory limit in KB", null=False, default=256 * 1024)

	def __unicode__(self):
		return "[{}: {}]".format(self.title, self.difficulty)

	@property
	def url(self):
		return self.title.lower().strip().replace(" ", "-")


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
	problem = models.ForeignKey(Problem, related_name="submissions")
	candidate = models.ForeignKey(Candidate, related_name="submissions")
	language = models.CharField(max_length=255, choices=Language.choices())
	source = models.TextField(verbose_name='source code')
	isSample = models.BooleanField(verbose_name='Compile and run sample tests or not', default=False)
	status = models.CharField(max_length=255,
	                          choices=SubmissionStatus.choices(), default=SubmissionStatus.QUEUED, null=True)

	originalCompilerErrorLog = models.TextField(default=None, null=True,
	                                            verbose_name="Compiler log returned from hacker earth api")
	compilerErrorLog = models.TextField(default=None, null=True,
	                                    verbose_name="Compiler log lines modified by our util function")

	timeUsed = models.DecimalField(default=0.00, null=True, max_digits=2, decimal_places=2,
	                               verbose_name="Time taken by the program")
	memoryUsed = models.PositiveIntegerField(default=0, null=True,
	                                         verbose_name="Memory used by the program in kilo bytes")

	failedCase = models.PositiveIntegerField(default=None, null=True,
	                                         verbose_name="Test Case # failed because of wrong answer")
	expected = models.TextField(default=None, null=True, verbose_name="Expected outcome for failed test case")
	obtained = models.TextField(default=None, null=True, verbose_name="Obtained outcome for failed test case")

	statusDetail = models.TextField(default=None, null=True, verbose_name="Signal like SIGSEGV, NZEC ...")
	stderr = models.TextField(default=None, null=True, verbose_name="Stderr used when run time error happens")


# Saves the draft for particular problem for an user
class Draft(models.Model):
	problem = models.ForeignKey(Problem, related_name="draft")
	candidate = models.ForeignKey(Candidate, related_name="drafts")
	language = models.CharField(max_length=255, choices=Language.choices())
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
	language = models.CharField(max_length=255, choices=Language.choices())
	problem = models.ForeignKey(Problem, related_name="problemFunctions")
	header = models.TextField()
	skeleton = models.TextField()
	footer = models.TextField()

	class Meta:
		unique_together = (('problem', 'language',),)

	def __unicode__(self):
		return "{}: {}".format(self.language, self.problem.name)
