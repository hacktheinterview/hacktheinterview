class Solution:
    def findLength(self, H1):
        tmp = H1
        length = 0
        while tmp != None:
            tmp = tmp.next
            length = length + 1
        return length

    def addTwoLists(self, H1, H2, diff):
        # return carry, node
        if not H1 and not H2:
            return 0, None

        if diff > 0:
            carry, tmp = self.addTwoLists(H1.next, H2, diff - 1)
            total = H1.val + carry
            carry = total/10
            H1.val = total % 10
            H1.next = tmp
            return carry, H1

        else:
            carry, tmp = self.addTwoLists(H1.next, H2.next, diff)
            total = H1.val + H2.val + carry
            carry = total/10
            H1.val = total % 10
            H1.next = tmp
            return carry, H1

        return 0, None

    def addTwoLinkedLists(self, H1, H2):
        len1 = self.findLength(H1)
        len2 = self.findLength(H2)

        if len2 > len1:
            H1, H2 = H2, H1

        carry, tmp = self.addTwoLists(H1, H2, abs(len1-len2))
        if carry > 0:
            head = ListNode(carry)
            head.next = tmp
            return head
        return tmp
