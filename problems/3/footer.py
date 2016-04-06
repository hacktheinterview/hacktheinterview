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
        L = LinkedList()
        lineItems = [int(l) for l in raw_input().split(" ")]
        nodes = lineItems[0]
        lineItems = lineItems[1:]

        for elem in lineItems:
            L.addNodeToEnd(elem)

        s = Solution()
        ret = s.isPalindromicList(L.head)
        print ret
