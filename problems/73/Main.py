#--SPLIT--

#--SPLIT--
# class Solution:
#     def primesum(self, a):

#--SPLIT--
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

#--SPLIT--

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        a = int(raw_input())
        s = Solution()
        print(s.primesum(a))