from __future__ import print_function
import math


#--SPLIT--
#-class Solution:
	# @param A : integer
	# @return a list of list of integers
#-	def generateMatrix(self, A):




#--SPLIT--
class Solution:
	# @param A : integer
	# @return a list of list of integers
	def generateMatrix(self, A):
		return []



#--SPLIT--

if __name__ == "__main__":
	test_cases = int(raw_input())
	for i in range(test_cases):
		A = int(raw_input())
		solution = Solution()
		result = solution.generateMatrix(A)
		for r in result:
			for x in r:
				print(str(x) + " ", end="")
			print("")
