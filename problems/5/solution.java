// ListNode type
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; next = null; }
// }

class Solution {
    public static ListNode removeDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode current = head;
        ListNode next = current.next;
        boolean duplicateFound = false;

	while (next != null && next.val == current.val) {
		next = next.next;
            duplicateFound = true;
	}

        if (duplicateFound) {
            current = removeDuplicates(next);
        } else {
            current.next = removeDuplicates(next);
        }
	return current;
    }
}
