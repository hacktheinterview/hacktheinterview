import math

#--SPLIT--
#-class Solution:
# @param a : list of strings
# @return a strings
#-	def longestCommonPrefix(self, a):

#--SPLIT--
class Solution:
	def longestCommonPrefix(self, a):
		return ""


#--SPLIT--
if __name__ == "__main__":
	test_cases = int(raw_input())
	for i in range(test_cases):
		inputLines = raw_input().split(" ")
		solution = Solution()
		print(solution.longestCommonPrefix(inputLines[1:]))
