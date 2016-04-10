
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

