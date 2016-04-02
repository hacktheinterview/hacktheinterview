// ListNode type
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; next = null; }
// }

class Solution {
    public static ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode current = head;
        ListNode next = current.next;
        ListNode reversed = reverseList(next);
        next.next = current;
        current.next = null;
        return reversed;
    }
}
