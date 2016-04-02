#!/usr/bin/python
# -*- coding: utf-8 -*-
import random
from hackerearth.parameters import SupportedLanguages
from hackerearth.parameters import RunAPIParameters

from hackerearth.api_handlers import HackerEarthAPI

client_secret = '0a7f0101e5cc06e4417a3addeb76164680ac83a4'

source = open('hackerearth/Solution.py', 'r').read()
input_source = open('hackerearth/input.txt', 'r').read()

lang = SupportedLanguages.PYTHON
compressed = 0
html = 0
print source
print input_source
params = RunAPIParameters(async=0,
			client_secret=client_secret,
			source=source,
        	lang=lang,
			compressed=1,
			id=random.randint(12123,123123),
			#program_input=input_source,
			#callback='http://sheltered-ocean-78784.herokuapp.com/test_url/'
	)


print params.__dict__

api = HackerEarthAPI(params)

print 'Compiling code..'
r = api.compile()
print r.__dict__

print '\nRunning code...'
r = api.run()
print r.__dict__
output = r.__dict__.get('output')

print '\nRun Output:'
print output
