ListNode* Solution::sortListUsingInsertionSort(ListNode* head) {
	if (!head || !head->next)
		return head;

	ListNode* newHead = new ListNode(head->val);
	ListNode* pointer = head->next;

	// loop through each element in the list
	while (pointer != NULL) {
		// insert this element to the new list

		ListNode* innerPointer = newHead;
		ListNode* next = pointer->next;

		if (pointer->val <= newHead->val) {
			ListNode* oldHead = newHead;
			newHead = pointer;
			newHead->next = oldHead;
		} else {
			while (innerPointer->next != NULL) {

				if (pointer->val > innerPointer->val && pointer->val <= innerPointer->next->val) {
					ListNode* oldNext = innerPointer->next;
					innerPointer->next = pointer;
					pointer->next = oldNext;
				}

				innerPointer = innerPointer->next;
			}

			if (innerPointer->next == NULL && pointer->val > innerPointer->val) {
				innerPointer->next = pointer;
				pointer->next = NULL;
			}
		}
		// finally
		pointer = next;
	}
	return newHead;
}
