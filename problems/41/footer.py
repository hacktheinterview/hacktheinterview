def print2DVector(result):
    sys.stdout.write("[")
    if result:
        for row in result:
            sys.stdout.write("[")
            for elem in row:
                sys.stdout.write(elem)
                sys.stdout.write(",")
            sys.stdout.write("]")
    sys.stdout.write("]")
    sys.stdout.flush()
    print

if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [l for l in raw_input().split(" ")]
        tokens = lineItems[1:]
        T = BinaryTree()
        T.constructFromTokens(tokens)
        s = Solution()
        result = s.levelOrder(T.root)
        print2DVector(result)
