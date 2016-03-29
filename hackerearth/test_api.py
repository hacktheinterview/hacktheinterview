#!/usr/bin/python
# -*- coding: utf-8 -*-

from parameters import SupportedLanguages
from parameters import RunAPIParameters

from api_handlers import HackerEarthAPI

client_secret = '0a7f0101e5cc06e4417a3addeb76164680ac83a4'

source = open('test_source.py', 'r').read()
lang = SupportedLanguages.PYTHON
compressed = 1
html = 0
params = RunAPIParameters(async=0,
        client_secret=client_secret, source=source,
        lang=lang,id=213123,
	#callback='http://sheltered-ocean-78784.herokuapp.com/test_url/'
)

api = HackerEarthAPI(params)

#print 'Compiling code..'
#r = api.compile()
#print r.__dict__

print '\nRunning code...'
r = api.run()
print r.__dict__
output = r.__dict__.get('output')

print '\nRun Output:'
print output
