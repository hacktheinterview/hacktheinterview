ListNode* Solution::reverseList(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* current = head;
	ListNode* next = current->next;
	ListNode* reversed = reverseList(next);
	next->next = current;
	current->next = NULL;
	return reversed;
}