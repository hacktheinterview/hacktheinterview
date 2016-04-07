ListNode* Solution::swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
		return head;
	}

    ListNode* prev = head;
    ListNode* curr = head->next;

    head = curr;
    while (true) {
        ListNode *next = curr->next;
        curr->next = prev; // Change next of current as previous node

        if (next == NULL || next->next == NULL) {
			prev->next = next;
			break;
        }

        prev->next = next->next;

        prev = next;
        curr = prev->next;
    }
	return head;
}
