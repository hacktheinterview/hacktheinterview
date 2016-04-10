import math

#--SPLIT--
#-class Solution:
    # @param A : integer
    # @return a strings
#-    def convertToTitle(self, a):



#--SPLIT--
class Solution:
    # @param A : integer
    # @return a strings
    def convertToTitle(self, a):
        result = ""
        while (a > 0):
            r = (a - 1) % 26
            result = chr(ord('A') + r) + result
            a = (a - 1) / 26
        return result


#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = int(raw_input())
        s = Solution()
        print(s.convertToTitle(a))