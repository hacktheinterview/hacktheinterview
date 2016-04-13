from __future__ import print_function
import math

#--SPLIT--
#-class Solution:
	# @param A : list of integers
	# @return a list of integers
#-	def maxset(self, A):

#--SPLIT--
class Solution:
	def maxset(self, A):
		return A


#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        A = [int(l) for l in raw_input().split(" ")][1:]
        solution = Solution()
        result = solution.maxset(A) 
        for r in result:
            print(str(r) + " ", end="")
        print("")