ListNode* removeDuplicates(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* current = head;
	ListNode* next = current->next;

	while (next && next->val == current->val) {
		next = next->next;
	}

	current->next = removeDuplicates(next);
	return current;
}
