if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        N = lineItems[0]
        K = lineItems[-1]
        inputArray = lineItems[1:-1]

        s = Solution()
        result = s.binarySearch(inputArray, K)
        print result
