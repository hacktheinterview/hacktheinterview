import math

#--SPLIT--
#-class Solution:
    # @param a : integer
    # @param b : integer
    # @return an integer
#-    def uniquePaths(self, a, b):



#--SPLIT--
class Solution:
    # @param a : integer
    # @param b : integer
    # @return an integer
    def uniquePaths(self, a, b):
        return 0


#--SPLIT--
if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        a, b = lineItems
        s = Solution()
        print(s.uniquePaths(a, b))