import math

#--SPLIT--
#-class Solution:
	# @param X : list of integers
	# @param Y : list of integers
	# Points are represented by (X[i], Y[i])
	# @return an integer
#-	def coverPoints(self, X, Y):

#--SPLIT--
class Solution:
	def coverPoints(self, X, Y):
		return 0


#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        n = int(raw_input())
        X = [int(l) for l in raw_input().split(" ")]
        Y = [int(l) for l in raw_input().split(" ")]
        solution = Solution()
        print(solution.coverPoints(X, Y))