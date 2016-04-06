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
