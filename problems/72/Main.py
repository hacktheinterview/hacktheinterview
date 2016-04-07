#--SPLIT--

import math

#--SPLIT--
#-class Solution:
    # @param A : integer
    # @return a boolean
#-    def isPower(self, A):

#--SPLIT--
class Solution:
    def isPower(self, a):
        if a == 1:
            return True
        for x in range(2, 1 + int(math.sqrt(a))):
            y = 2
            p = x ** y
            while (p <= a):
                if p == a:
                    return True
                y = y + 1
                p = x ** y
        return False

#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = int(raw_input())
        s = Solution()
        print("1" if s.isPower(a) else "0")