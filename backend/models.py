from django.contrib.auth.models import User
from django.db import models
from backend.enums import ProblemCategory, ProblemDifficultyType, ProblemName, CompanyName, LanguageType


class Company(models.Model):
	name = models.CharField(max_length=255, choices=CompanyName.choices())


class Problem(models.Model):
	name = models.CharField(max_length=255, choices=ProblemName.choices())
	category = models.CharField(max_length=255, choices=ProblemCategory.choices())
	difficulty = models.CharField(max_length=255, choices=ProblemDifficultyType.choices())

	companies = models.ManyToManyField(Company, related_name='problems')

	@property
	def url(self):
		return self.name.lower().strip().replace(" ", "-")


class TestCase(models.Model):
	problem = models.ForeignKey(Problem, related_name="testCases")


class Candidate(models.Model):
	name = models.CharField(max_length=255)
	user = models.OneToOneField(User, related_name="candidate", on_delete=models.CASCADE)


class Submission(models.Model):
	problem = models.ForeignKey(Problem, related_name="submissions")
	candidate = models.ForeignKey(Candidate, related_name="submissions")
	language = models.CharField(max_length=255, choices=LanguageType.choices())

	class Meta:
		unique_together = ('problem', 'candidate')







# class Problem(models.Model):
# 	problem_id = models.IntegerField(primary_key=True)
# 	title = models.CharField(max_length=100)
# 	previewtext = models.TextField()
# 	content = models.TextField()
# 	types = models.TextField()
# 	companies = models.TextField()
# 	totalsubmission = models.IntegerField()
# 	passedsubmissions = models.IntegerField()
# 	difficulty = models.IntegerField()
#
# 	time_limit_per_test_case = models.IntegerField()
# 	memory_limit_per_test_case = models.IntegerField()
# 	sample_test_cases_count = models.IntegerField()
# 	test_cases_count = models.IntegerField()
# 	is_driver_enabled = models.BooleanField(default=False)
#
# 	class Meta:
# 		db_table = "Problem"
#
# 	def __unicode__(self):
# 		return "%d->%s" % (self.problem_id, self.title)


class Submission(models.Model):
	run_id = models.IntegerField(primary_key=True)
	user_id = models.IntegerField()
	problem = models.ForeignKey(Problem)
	source_code = models.TextField()
	submission_time = models.DateTimeField()
	status = models.CharField(max_length=50)
	language = models.CharField(max_length=20)
	issubmission = models.BooleanField(default=False)
	compiler_error_log = models.TextField()

	# Maximum time taken
	time_taken = models.IntegerField()

	exit_code = models.IntegerField()

	class Meta:
		db_table = "Submission"

	def __unicode__(self):
		return "User_Id: %d \n run_id %d " % (self.user_id, self.run_id)


class Submission_unitrun(models.Model):
	Submission = models.ForeignKey(Submission)
	time_taken = models.IntegerField()
	exit_code = models.IntegerField()
	output = models.TextField()
	result = models.CharField(max_length=100)
	testcase_no = models.IntegerField()

	class Meta:
		db_table = "Submission_unitrun"

	def __unicode__(self):
		return "Submission Id:%d, Testcase_no %d" % (self.Submission.run_id, self.testcase_no)


class Problem_Functions(models.Model):
	problem = models.ForeignKey(Problem)
	c_code = models.TextField()
	c_main_code = models.TextField()
	cpp_code = models.TextField()
	cpp_main_code = models.TextField()
	java_code = models.TextField()
	java_main_code = models.TextField()

	class Meta:
		db_table = "Problem_Functions"

	def __unicode__(self):
		return "%d->%s" % (self.problem.problem_id, self.problem.title)
