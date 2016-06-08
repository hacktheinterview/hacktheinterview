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
    public static ListNode mergeKLists(ListNode[] lists) {
        if(lists==null||lists.length==0)
            return null;

        PriorityQueue<ListNode> queue = new PriorityQueue<ListNode>(new Comparator<ListNode>(){
            public int compare(ListNode l1, ListNode l2){
                return l1.val - l2.val;
            }
        });

        ListNode head = new ListNode(0);
        ListNode p = head;

        for(ListNode list: lists){
            if(list!=null)
                queue.offer(list);
        }

        while(!queue.isEmpty()){
            ListNode n = queue.poll();
            p.next = n;
            p=p.next;

            if(n.next!=null)
                queue.offer(n.next);
        }

        return head.next;

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

            int x = 0;
            int numLists = Integer.parseInt(inputItems[0]);
            x++;
            ListNode[] lists = new ListNode[numLists];

            for (int j = 0; j < numLists; j++) {
                int numNodes = Integer.parseInt(inputItems[x]);
                x++;
                LinkedList L = new LinkedList();
                while (numNodes > 0) {
                    L.addNodeToEnd(Integer.parseInt(inputItems[x]));
                    x++;
                    numNodes--;
                }
                lists[j] = L.head;
            }

            Solution s = new Solution();
            LinkedList resultList = new LinkedList();
            resultList.head = s.mergeKLists(lists);
            resultList.printLinkedList();
        }
    }
}
