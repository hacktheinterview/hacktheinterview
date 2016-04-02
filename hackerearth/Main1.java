import java.io.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

class LinkedList {
    public ListNode head;
    public ListNode tail;

    LinkedList() {}
    public void addNodeToEnd(int val) {
        ListNode tmp = new ListNode(val);
        if (head == null) {
            head = tmp;
            head.next = null;
            tail = head;
        } else {
            tail.next = tmp;
            tail = tail.next;
        }
    }

    public void printLinkedList() {
        if (head == null) {
		return;
	}

	ListNode tmp = head;
	while(tmp.next != null) {
            System.out.print(tmp.val);
            System.out.print(" -> ");
		tmp = tmp.next;
	}

        System.out.println(tmp.val);
    }
}

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

public class Main1 {
    public static void main(String args[]) {
        LinkedList l = new LinkedList();
        for (int i = 0; i < 5; i ++) {
            l.addNodeToEnd(i);
        }
        l.printLinkedList();

        Solution s = new Solution();
        ListNode reversedHead = s.reverseList(l.head);
        l.head = reversedHead;
        l.printLinkedList();
    }
}
