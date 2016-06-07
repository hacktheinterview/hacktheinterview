def printList(result):
    if not result:
        print ""
        return
    print " ".join(str(item) for item in result)

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
        N = lineItems[0]
        K = lineItems[-1]
        inputArray = lineItems[1:-1]

        s = Solution()
        result = s.topKFrequent(inputArray, K)
        printList(result)
