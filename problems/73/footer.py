
class Solution:
    def primesum(self, a):
        isPrime = {}
        for i in range(2, a + 1):
            isPrime[i] = True

        for i in range(2, a + 1):
            for j in range(2, 1 + (a + 1) / i):
                isPrime[i * j] = False

        for i in range(2, a):
            j = a - i
            if (isPrime[i] and isPrime[j]):
                return [i, j]

        return None

