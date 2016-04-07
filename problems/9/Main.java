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

            int numNodes = Integer.parseInt(inputItems[0]);
            LinkedList L = new LinkedList();
            int x = 0;
            for (x = 1; x <= numNodes; x++) {
                L.addNodeToEnd(Integer.parseInt(inputItems[x]));
            }

            Solution s = new Solution();
            L.head = s.swapPairs(L.head);
            L.printLinkedList();
        }
    }
}
