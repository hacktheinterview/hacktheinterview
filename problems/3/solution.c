int isPalindromeUtil(ListNode** left, ListNode *right) {
   if (right == NULL) {
       return 1;
   }


   int ret = isPalindromeUtil(left, right->next);
   if (!ret)
      return 0;

   if (right->val == (*left)->val) {
       ret = 1;
   } else {
       ret = 0;
   }

   *left = (*left)->next;
   return ret;
}

int isPalindromicList(ListNode* head) {
    // Implement the function
    return isPalindromeUtil(&head, head);
}
