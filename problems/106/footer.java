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


            int numLists = Integer.parseInt(inputItems[0]);

            ListNode[] lists = new ListNode[numLists];
            int x = 1;

            for (int j = 0; j < numLists; j++) {
                int numNodes = Integer.parseInt(inputItems[x]);
                x++;
                LinkedList L = new LinkedList();
                while (numNodes > 0) {
                    L.addNodeToEnd(Integer.parseInt(inputItems[x]));
                    x++;
                    numNodes = numNodes - 1;
                }
                lists[j] = L;
            }

            Solution s = new Solution();
            LinkedList resultList = new LinkedList();
            resultList.head = s.mergeKLists(lists);
            resultList.printLinkedList();
        }

    }
}
