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

class LinkedList {
    ListNode head;
    ListNode tail;

    LinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void addNodeToEnd(int val) {
        ListNode tmp = new ListNode(val);
        tmp.next = null;
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
            System.out.println();
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

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");

            int numNodes1 = Integer.parseInt(inputItems[0]);
            LinkedList L1 = new LinkedList();
            int x = 0;
            for (x = 1; x <= numNodes1; x++) {
                L1.addNodeToEnd(Integer.parseInt(inputItems[x]));
            }

            int numNodes2 = Integer.parseInt(inputItems[x]);
            LinkedList L2 = new LinkedList();
            x = x + 1;
            for (; x < inputItems.length; x++) {
                L2.addNodeToEnd(Integer.parseInt(inputItems[x]));
            }

            Solution s = new Solution();
            ListNode mergedHead = s.mergeTwoSortedLinkedLists(L1.head, L2.head);
            L1.head = mergedHead;
            L1.printLinkedList();
        }

    }
}
