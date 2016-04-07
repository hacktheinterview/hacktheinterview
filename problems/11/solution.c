ListNode* oddEvenLinkedList(ListNode* head) {
	if (!head) {
		return head;
	}
	ListNode* odd = head;
	ListNode* even = head -> next;
	ListNode* evenHead = even;
	while (even != NULL && even->next != NULL) {
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}
