// ListNode type
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; next = null; }
// }

class Solution {
    public static int findLength(ListNode H1) {
        ListNode tmp = H1;
        int len = 0;
        while (tmp != null) {
            tmp = tmp.next;
            len++;
        }
        return len;
    }

    public static ListNode rotateList(ListNode head, int n) {
    	if (head == null || head.next == null) {
    		return head;
    	}

    	int len = findLength(head);
    	if (n >= len)
    		n = n % len;

    	if (n == 0) {
    		return head;
    	}

    	int diff = len - n;

    	ListNode newHead = head;
    	ListNode prev = newHead;
    	for (int i = 0; i < diff; i++) {
    		prev = newHead;
    		newHead = newHead.next;
    	}

    	ListNode tail = head;
    	while (tail.next != null) {
    		tail = tail.next;
    	}

    	tail.next = head;
    	prev.next = null;
    	return newHead;
    }
}
