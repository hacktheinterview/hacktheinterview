if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        B = lineItems[-1]
        A = lineItems[-2]
        tokens = lineItems[1:-2]
        T = BinaryTree()
        T.constructFromTokens(tokens)
        s = Solution()
        result = s.lca(T.root, A, B)
        print result
