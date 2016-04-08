int findLength(ListNode* H1) {
    ListNode* tmp = H1;
    int len = 0;
    while (tmp != NULL) {
        tmp = tmp->next;
        len++;
    }
    return len;
}

ListNode* Solution::rotateList(ListNode* head, int n) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	int len = findLength(head);
	if (n >= len)
		n = n % len;

	if (n == 0) {
		return head;
	}

	int diff = len - n;

	ListNode* newHead = head;
	ListNode* prev = newHead;
	for (int i = 0; i < diff; i++) {
		prev = newHead;
		newHead = newHead->next;
	}

	ListNode* tail = head;
	while (tail->next) {
		tail = tail->next;
	}

	tail->next = head;
	prev->next = NULL;
	return newHead;
}
