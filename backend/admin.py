from django.contrib import admin
from backend.models import *

admin.site.register(Problem)
admin.site.register(Submission)
admin.site.register(TestCase)

class ProblemAdmin(admin.ModelAdmin):
	pass

class SubmissionAdmin(admin.ModelAdmin):
	pass

class TestcaseAdmin(admin.ModelAdmin):
	pass
