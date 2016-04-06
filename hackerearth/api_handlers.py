import json
import urllib
import urllib2
import requests

from settings import COMPILE_API_ENDPOINT
from settings import RUN_API_ENDPOINT
from settings import CLIENT_SECRET

from result import CompileResult
from result import RunResult


class HackerEarthAPI(object):
	def __init__(self, params):
		self.params_dict = params.get_params()

	def compile(self):
		print(self.params_dict)
		response = self.__request(COMPILE_API_ENDPOINT, self.params_dict)
		result = CompileResult(response.text)
		if response.status_code != 200:
			result.valid = False
		else:
			result.valid = True
		return result

	def run(self):
		print(self.params_dict)
		response = self.__request(RUN_API_ENDPOINT, self.params_dict)
		result = RunResult(response.text)
		if response.status_code != 200:
			result.valid = False
		else:
			result.valid = True
		return result

	def __request(self, url, params):
		response = None
		try:
			response = requests.post(url, data=params)
		except Exception as e:
			print(e)
		return response

	def __result(self, res):
		result = json.load(res)
		return result
