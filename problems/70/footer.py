
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


