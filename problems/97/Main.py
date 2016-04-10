import math


#--SPLIT--
# -class Solution:
# @param A : tuple of integers
# @return a list of integers
# -	def repeatedNumber(self, A):


#--SPLIT--
class Solution:
	# @param A : tuple of integers
	# @return a list of integers
	def repeatedNumber(self, A):
		return A


#--SPLIT--

if __name__ == "__main__":
	test_cases = int(raw_input())
	for i in range(test_cases):
		A = [int(l) for l in raw_input().split(" ")][1:]
		solution = Solution()
		result = solution.repeatedNumber(A)
		print("{0} {1} ".format(result[0], result[1]))
