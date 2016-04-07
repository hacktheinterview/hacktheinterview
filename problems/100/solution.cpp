ListNode* Solution::removeDuplicates(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* current = head;
	ListNode* next = current->next;

	int dup = 0;
	while (next && next->val == current->val) {
		dup = 1;
		next = next->next;
	}

	if (dup == 1) {
		return removeDuplicates(next);
	} else {
		current->next = removeDuplicates(next);
		return current;
	}
}
