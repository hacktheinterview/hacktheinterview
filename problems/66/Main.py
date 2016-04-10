import math

#--SPLIT--
#-class Solution:
    # @param a : integer
    # @return an integer
#-    def trailingZeroes(self, a):

#--SPLIT--
class Solution:
    def trailingZeroes(self, a):
        result = 0
        while (a > 0):
            result += a / 5
            a = a / 5
        return result


#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = int(raw_input())
        s = Solution()
        print(s.trailingZeroes(a))