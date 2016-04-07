ListNode* reverseList(ListNode* head) {
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

ListNode* rearrangeLinkedList(ListNode* head) {
	if (!head) {
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = slow->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* head1 = head;
	ListNode* head2 = slow->next;

	slow->next = NULL;

	head2 = reverseList(head2);

	head = (ListNode*) malloc(sizeof(ListNode));
	head->val = 0;
	head->next = NULL;

    // curr is the pointer to this dummy Node, which will
    // be used to form the new list
    ListNode* curr = head;
    while (head1 || head2)
    {
        // First add the element from list
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        // Then add the element from second list
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    // Assign the head of the new list to head pointer
    head = head -> next;
	return head;
}
