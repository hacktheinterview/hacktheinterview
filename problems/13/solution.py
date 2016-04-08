class Solution:
    def removeNthNodeFromList(self, head, N):
        if not head:
            return None

        fast, slow = head, head

        for i in range(N):
            fast = fast.next

        # Remove the first node
        if fast == None:
            head = head.next
            return head

        while fast.next != None:
            fast = fast.next;
            slow = slow.next;

        slow.next = slow.next.next
        return head
