from __future__ import print_function
import math

#--SPLIT--
#-class Solution:
    # @param a : list of integers
    # Modify the array a which is passed by reference. 
#-    def arrange(self, a):


#--SPLIT--
class Solution:
    def arrange(self, a):
        pass


#--SPLIT--
if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        a = lineItems[1:]
        s = Solution()
        s.arrange(a)
        for x in a:
            print("{0} ".format(x), end="")
        print("")