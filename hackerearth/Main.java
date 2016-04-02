import java.io.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
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
public class Main {
    static ListNode head;
    static ListNode tail;

    public static void addNodeToEnd(int val) {
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

    public static void printLinkedList(ListNode head) {
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

    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            head = null; tail = null;
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");
            int numNodes = Integer.parseInt(inputItems[0]);
            for (int x = 1; x <= numNodes; x++) {
                addNodeToEnd(Integer.parseInt(inputItems[x]));
            }
            Solution s = new Solution();
            ListNode reversedHead = s.reverseList(head);
            printLinkedList(reversedHead);
        }

    }
}
