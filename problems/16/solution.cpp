ListNode* Solution::reverseNodesFromMtoN(ListNode* head, int M, int N) {
    ListNode* newHead = new ListNode(-1);
    newHead->next = head;
    ListNode* prev = newHead;
    for(int i = 0 ; i < M - 1 ; i++) {
        prev = prev->next;
    }
    ListNode* const reversedPrev = prev;
    //position m
    prev = prev->next;
    ListNode* cur = prev->next;
    for(int i = M ; i < N ; i++) {
        prev->next = cur->next;
        cur->next = reversedPrev->next;
        reversedPrev->next = cur;
        cur = prev->next;
    }
    return newHead->next;
}
