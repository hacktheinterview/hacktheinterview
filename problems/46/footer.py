if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        n = int(lineItems[0])
        inorder = lineItems[1:(n + 1)]
        preorder = lineItems[(n + 1):]

        s = Solution()
        root = s.constructBinaryTree(inorder, preorder)
        T = BinaryTree()
        T.root = root
