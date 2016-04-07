class Solution:
    def oddEvenLinkedList(self, head):
        if not head:
            return None
        odd = head
        even = head.next
        evenHead = even

        while even != None and even.next != None:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        odd.next = evenHead
        return head
