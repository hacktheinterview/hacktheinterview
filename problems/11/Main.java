// ListNode type
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; next = null; }
// }

class Solution {
    public static ListNode oddEvenLinkedList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
}
