// ListNode type
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; next = null; }
// }

class Solution {
    public static ListNode mergeTwoSortedLinkedLists(ListNode H1, ListNode H2) {
        if (H1 == null) {
            return H2;
        }
        if (H2 == null) {
            return H1;
        }
        ListNode tmp = H1;
        if (tmp.val > H2.val) {
            tmp = H2;
            tmp.next = mergeTwoSortedLinkedLists(H1, H2.next);
        } else {
            tmp.next = mergeTwoSortedLinkedLists(H1.next, H2);
        }
        return tmp;
    }
}
