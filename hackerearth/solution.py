class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def addNodeToEnd(self, val):
        tmp = ListNode(val)
        if self.head == None:
            self.head = tmp
            self.head.next = None
            self.tail = self.head
        else:
            self.tail.next = tmp
            self.tail = self.tail.next

    def printLinkedList(self):
        tmp = self.head
        if not tmp:
            print ""
            return

        output = ""
        while tmp != None:
            if tmp.next:
                output = "{}{} -> ".format(output, tmp.val)
            else:
                output = "{}{}".format(output, tmp.val)
            tmp = tmp.next

        print output


class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class Solution:
    def reverseList(self, head):
        if not head or not head.next:
            return head

        current = head
        nextNode = current.next
        reversedHead = reverseList(nextNode)
        nextNode.next = current
        current.next = None
        return reversedHead


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
    l = LinkedList()
    for i in range(10):
        l.addNodeToEnd(i)
    l.printLinkedList()

    s = Solution()
    reversedHead = s.reverseList(l.head)
    l.head = reversedHead
    l.printLinkedList()
