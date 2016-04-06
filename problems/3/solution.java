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
