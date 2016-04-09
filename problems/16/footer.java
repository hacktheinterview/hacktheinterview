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

            int M = Integer.parseInt(inputItems[inputItems.length - 2]);
            int N = Integer.parseInt(inputItems[inputItems.length - 1]);

            Solution s = new Solution();
            ListNode newHead = s.reverseNodesFromMtoN(L.head, M, N);
            L.head = newHead;
            L.printLinkedList();
        }
    }
}
