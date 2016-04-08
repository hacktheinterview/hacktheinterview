#--SPLIT--

import math

#--SPLIT--
#-class Solution:
    # @param A : string
    # @return an integer
#-    def titleToNumber(self, a):


#--SPLIT--
class Solution:
    def titleToNumber(self, a):
        result = 0
        for i, c in enumerate(a):
            c = a[len(a) - i - 1]
            result += (ord(c) - ord('A') + 1) * 26**i
        return result

#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = raw_input()
        s = Solution()
        print(s.titleToNumber(a))