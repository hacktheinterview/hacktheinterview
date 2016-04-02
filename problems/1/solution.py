class Solution:
    def reverseList(self, head):
        if not head or not head.next:
            return head

        current = head
        nextNode = current.next
        reversedHead = self.reverseList(nextNode)
        nextNode.next = current
        current.next = None
        return reversedHead
