if __name__ == "__main__":
    test_cases = int(raw_input())
    for i in range(test_cases):
        lineItems = [int(l) for l in raw_input().split(" ")]
	numNodes1 = lineItems[0]
	nodes1 = lineItems[1:(numNodes1 + 1)]
	numNodes2 = lineItems[numNodes1 + 1]
	nodes2 = lineItems[numNodes1 + 2:]

        L1 = LinkedList()
        for elem in nodes1:
            L1.addNodeToEnd(elem)

        L2 = LinkedList()
        for elem in nodes2:
            L2.addNodeToEnd(elem)

        s = Solution()
        L1.head = s.mergeTwoSortedLinkedListsInReverse(L1.head, L2.head)
        L1.printLinkedList()
