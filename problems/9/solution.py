class Solution:
    def swapPairs(self, head):
        if not head or not head.next:
            return head

        prev = head
        curr = head.next
        head = curr

        while True:
            nextNode = curr.next
            curr.next = prev

            if not nextNode or not nextNode.next:
    			prev.next = nextNode
    			break

            prev.next = nextNode.next
            prev = nextNode
            curr = prev.next

        return head
