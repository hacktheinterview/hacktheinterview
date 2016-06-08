def addNodeToEnd(head, tail, val):
    tmp = ListNode(val)

    if head == None:
        head = tmp
        head.next = None
        tail = head
        print head.val
    else:
        tail.next = tmp
        tail = tail.next

def printLinkedList(head):
    if not head:
        print ""
        return

    tmp = head
    output = ""
    while tmp != None:
        if tmp.next:
            output = "{}{} -> ".format(output)
        else:
            output = "{}{}".format(output, tmp.val)

        tmp = tmp.next

    print output

if __name__ == "__main__":
    test_cases = int(raw_input())

    for i in range(test_cases):
        inputItems = [int(l) for l in raw_input().split(" ")]
        numLists = int(inputItems[0])
        lists = []
        x = 1

        for j in range(numLists):
            numNodes = int(inputItems[x])
            x = x + 1
            L = LinkedList();
            while numNodes > 0 :
                L.addNodeToEnd(int(inputItems[x]))
                x = x + 1
                numNodes = numNodes - 1
                lists.append(L.head)

        Solution s = Solution()
        mergedHead =  = s.mergeKLists(lists)
        L = LinkedList()
        L.head = mergedHead
        L.printLinkedList()
