#--SPLIT--

import math

#--SPLIT--
#-class Solution:
    # @param A : integer
    # @return a boolean value ( True / False )
#-    def isPalindrome(self, a):



#--SPLIT--
class Solution:
    def isPalindrome(self, a):
        return str(a) == str(a)[::-1]


#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = int(raw_input())
        s = Solution()
        print("1" if s.isPalindrome(a) else "0")