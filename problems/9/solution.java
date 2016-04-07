// ListNode type
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; next = null; }
// }
class Solution {
    public static ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode prev = head;
        ListNode curr = head.next;

        head = curr;
        while (true) {
            ListNode next = curr.next;
            curr.next = prev; // Change next of current as previous node

            if (next == null || next.next == null) {
                prev.next = next;
                break;
            }

            prev.next = next.next;

            prev = next;
            curr = prev.next;
        }
        return head;

    }
}
