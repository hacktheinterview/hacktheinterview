from django.conf.urls import include, url

from django.contrib import admin

from backend.views import *

admin.autodiscover()

urlpatterns = [
	url(r'^$', home),
	url(r'^home/$', home),
	# url(r'^admin/doc/', include('django.contrib.admindocs.urls')),
	url(r'^admin/', include(admin.site.urls)),

	url(r'^test_url/', test_url),
	url(r'^create_submission/', createSubmission),
	url(r'^problem/(?P<problem_id>(\d+))/', problemPage),
	url(r'^get_submission_status/', getSubmissionStatus),
	url(r'^get_recent_submission/', getRecentSubmission),
]
