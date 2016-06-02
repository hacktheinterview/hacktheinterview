def printList(result):
    if not result:
        print ""
        return
    print " ".join(str(item) for item in result)

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        tokens = lineItems[1:]

        T = BinaryTree()
        T.constructFromTokens(tokens)
        s = Solution()
        result = s.preorderTraversal(T.root)
        printList(result)
