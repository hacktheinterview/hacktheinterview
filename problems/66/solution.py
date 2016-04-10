
class Solution:
    def trailingZeroes(self, a):
        result = 0
        while (a > 0):
            result += a / 5
            a = a / 5
        return result


