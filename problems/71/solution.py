
class Solution:
    def titleToNumber(self, a):
        result = 0
        for i, c in enumerate(a):
            c = a[len(a) - i - 1]
            result += (ord(c) - ord('A') + 1) * 26**i
        return result

