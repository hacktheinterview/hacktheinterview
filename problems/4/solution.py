class Solution:
    def removeDuplicates(self, head):
        if not head or not head.next:
            return head

        current = head
        nextNode = current.next

        while nextNode and nextNode.val == current.val:
            nextNode = nextNode.next;

        current.next = self.removeDuplicates(nextNode)
        return current
