class Solution:
    def partitionLinkedList(self, head, N):
        if not head:
            return None

        p = ListNode(0)
        p.next = head
        head = p
        last = head
        if head.next == None:
            return head.next

        n = 0
        while last.next != None:
            last = last.next
            n = n + 1


        while n > 0:
            if p.next.val < N:
                p = p.next
                n = n - 1
            else:
                last.next = ListNode(p.next.val)
                last = last.next
                p.next = p.next.next
                n = n - 1

        return head.next
