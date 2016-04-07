ListNode* Solution::removeNthNodeFromList(ListNode* head, int n) {
	if (!head) {
		return NULL;
	}

    ListNode* fast = head;
    ListNode* slow = head;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    //if remove the first node
    if (fast == NULL) {
        head = head->next;
        return head;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}
