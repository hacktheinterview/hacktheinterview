class Solution:
    def removeDuplicates(self, head):
        if not head or not head.next:
            return head

        current = head
        nextNode = current.next

        duplicateFound = False
        while nextNode and nextNode.val == current.val:
            duplicateFound = True
            nextNode = nextNode.next;

        if duplicateFound:
            current = self.removeDuplicates(nextNode)
        else:
            current.next = self.removeDuplicates(nextNode)

        return current
