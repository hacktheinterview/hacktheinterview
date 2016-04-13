from __future__ import print_function
import math

#--SPLIT--
#-class Solution:
	# @param A : integer
	# @return a list of integers
#-	def getRow(self, A):


#--SPLIT--
class Solution:
	def getRow(self, A):
		return []

#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        A = int(raw_input())
        solution = Solution()
        result = solution.getRow(A) 
        for r in result:
            print(str(r) + " ", end="")
        print("")