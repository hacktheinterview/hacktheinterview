class Solution:
    def findMin(self, A):
        lo = 0
        hi = len(A) - 1

        # 5, 1, 2, 3, 4
        while A[lo] > A[hi]:
            mid = (lo + hi) / 2
            if A[mid] > A[hi]:
                lo = mid + 1
            else:
                hi = mid
        return A[lo]

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        N = lineItems[0]
        inputArray = lineItems[1:]

        s = Solution()
        result = s.findMin(inputArray)
        print result
