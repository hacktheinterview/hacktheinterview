if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        L = LinkedList()
        lineItems = [int(l) for l in raw_input().split(" ")]
        nodes = lineItems[0]
        N = lineItems[-1]
        lineItems = lineItems[1:-1]

        for elem in lineItems:
            L.addNodeToEnd(elem)

        s = Solution()
        newHead = s.reverseEveryKNodes(L.head, N)
        L.head = newHead
        L.printLinkedList()
