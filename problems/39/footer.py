if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        tokens = lineItems[1:-1]
        K = int(lineItems[-1])
        T = BinaryTree()
        T.constructFromTokens(tokens)
        s = Solution()
        result = s.isPairPresent(T.root, K)
        print result
