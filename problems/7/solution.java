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

    public static ListNode rearrangeLinkedList(ListNode head) {
        if (head == null) {
		return head;
	}

	ListNode slow = head;
	ListNode fast = slow.next;

	while (fast != null && fast.next != null) {
		slow = slow.next;
		fast = fast.next.next;
	}

	ListNode head1 = head;
	ListNode head2 = slow.next;

	slow.next = null;

	head2 = reverseList(head2);

	head = new ListNode(0); // Assign dummy Node

        // curr is the pointer to this dummy Node, which will
        // be used to form the new list
        ListNode curr = head;
        while (head1 != null || head2 != null) {
            // First add the element from list
            if (head1 != null) {
                curr.next = head1;
                curr = curr.next;
                head1 = head1.next;
            }

            // Then add the element from second list
            if (head2 != null) {
                curr.next = head2;
                curr = curr.next;
                head2 = head2.next;
            }
        }

        // Assign the head of the new list to head pointer
        head = head.next;
	return head;

    }
}
