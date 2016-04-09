class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return an integer

    @staticmethod
    def lowerBound(A, B, lo, hi):
        if (hi >= lo):
            mid = (lo + hi) / 2
            if (A[mid] == B) and (mid == 0 or A[mid - 1] < B):
                return mid
            if A[mid] < B:
                return Solution.lowerBound(A, B, mid+1, hi)
            else:
                return Solution.lowerBound(A, B, lo, mid - 1)

        else:
            return -1

    @staticmethod
    def upperBound(A, B, lo, hi):
        if hi >= lo:
            mid = (lo + hi) / 2
            if (A[mid] == B) and (mid == len(A)-1 or A[mid+1] > B):
                return mid
            if A[mid] > B:
                return Solution.upperBound(A, B, lo, mid - 1)
            else:
                return Solution.upperBound(A, B, mid + 1, hi)
        else:
            return -1

    def ceilSearch(self, A, K):
        lower_index = self.lowerBound(A, K, 0, len(A) - 1)
        if lower_index == -1:
            return 0
        # return lower_index
        upper_index = self.upperBound(A, K, 0, len(A) - 1)
        #return upper_index
        return upper_index - lower_index + 1


if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        N = lineItems[0]
        K = lineItems[-1]
        inputArray = lineItems[1:-1]

        s = Solution()
        result = s.findCount(inputArray, K)
        print result
