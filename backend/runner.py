from hacktheinterview.settings import IDEONE_PASSWORD
from hacktheinterview.settings import IDEONE_USERNAME

from backend.ideone import Ideone

class Runner(object):
	def __init__(self):
		self.ideone = Ideone(IDEONE_USERNAME, IDEONE_PASSWORD)

	def test(self):
		return self.ideone.test()

	def submit(self, solution, languageName):
		return self.ideone.create_submission(solution, language_name=languageName)
