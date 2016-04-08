class Solution:
    def findLength(self, head):
        tmp = head
        length = 0
        while tmp != None:
            tmp = tmp.next
            length = length + 1
        return length

    def rotateList(self, head, N):
        if head == None or head.next == None:
            return head

        length = self.findLength(head)
        if N >= length:
            N = N % length

        if N == 0:
            return head

        diff = length - N

        newHead = head
        prev = newHead
        for i in range(diff):
            prev = newHead
            newHead = newHead.next

        tail = head
        while tail.next:
            tail = tail.next

        tail.next = head
        prev.next = None
        return newHead
