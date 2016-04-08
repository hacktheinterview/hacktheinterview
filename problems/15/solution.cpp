ListNode* Solution::reverseEveryKNodes(ListNode* head, int K) {
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    while (current != NULL && count < K) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseEveryKNodes(next, K);
    }
    return prev;
}
