import java.io.*;
import java.util.*;

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
    public static int isPalindromicList(ListNode head) {
        Stack<Integer> stack = new Stack<Integer>();
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
          stack.push(slow.val);
          slow = slow.next;
          fast = fast.next.next;
        }
        // if list has odd number of elements
        if (fast != null) {
          slow = slow.next;
        }

        while (slow != null) {
          int top = stack.pop();
          if (slow.val != top) {
            return 0;
          }
          slow = slow.next;
        }
        return 1;
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

    public static void printInteger(int result) {
        System.out.println(result);
    }

    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");

            int numNodes1 = Integer.parseInt(inputItems[0]);
            LinkedList L = new LinkedList();
            int x = 0;
            for (x = 1; x <= numNodes1; x++) {
                L.addNodeToEnd(Integer.parseInt(inputItems[x]));
            }

            Solution s = new Solution();
            int result = s.isPalindromicList(L.head);
            printInteger(result);
        }

    }
}
