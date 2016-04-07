class Solution:
    def mergeTwoSortedLinkedLists(self, H1, H2):
        if not H1:
            return H2
        if not H2:
            return H1

        tmp = H1
        if tmp.val > H2.val:
            tmp = H2
            tmp.next = self.mergeTwoSortedLinkedLists(H1, H2.next)
        else:
            tmp = H1
            tmp.next = self.mergeTwoSortedLinkedLists(H1.next, H2)
        return tmp
