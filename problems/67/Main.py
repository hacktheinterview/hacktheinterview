import math

#--SPLIT--
#-class Solution:
    # @param a : integer
    # @param b : integer
    # @return an integer
#-    def gcd(self, a, b):

#--SPLIT--
class Solution:
    def gcd(self, a, b):
        if a  == 0:
            return b
        return self.gcd(b%a, a)


#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a, b = [int(l) for l in raw_input().split(" ")]
        s = Solution()
        print(s.gcd(a, b))