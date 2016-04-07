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

    def rearrangeLinkedList(self, head):
        # pass
        if not head:
            return head

        slow = head
        fast = slow.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        head1 = head
        head2 = slow.next

        slow.next = None
        head2 = self.reverseList(head2)

        head = ListNode(0)

        curr = head

        while head1 or head2:
            if head1:
                curr.next = head1
                curr = curr.next
                head1 = head1.next

            if head2:
                curr.next = head2
                curr = curr.next
                head2 = head2.next

        head = head.next
        return head
