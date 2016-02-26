from django.conf.urls import patterns, include, url

# Uncomment the next two lines to enable the admin:
from django.contrib import admin

from backend.views import *

admin.autodiscover()

urlpatterns = patterns('',
    url(r'^$', home),
	url(r'^home/$',home),
    # Examples:
    # url(r'^$', 'Site.views.home', name='home'),
    # url(r'^Site/', include('Site.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    url(r'^submit/',submit),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^get_problems_by_type/',get_problems_by_type),
    url(r'^problem/(\d+)/',problem),
    url(r'^submissions/(\d+)/',submissions),
    url(r'^submissions/my/$',getmysubmissions),
    url(r'^compile_and_test/',compile_and_test),
    url(r'^get_compilation_result/',get_compilation_result),
    url(r'^get_compilation_status/',get_compilation_status),
)
