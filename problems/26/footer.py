if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        N = lineItems[0]
        lineItems = lineItems[1: -1]
        A = lineItems[-1]
        s = Solution()
        result = s.copyBooks(A, lineItems)
        print result
