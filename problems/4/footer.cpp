void addNodeToEnd(ListNode*& head, int val) {
	ListNode* tmp = new ListNode(val);
	if (head == NULL) {
		head = tmp;
		head->next = NULL;
	} else {
		ListNode* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = tmp;
	}
}

void printLinkedList(ListNode* head) {
	if (!head) {
		cout << endl;
		return;
	}
	ListNode* tmp = head;
	while(tmp->next != NULL) {
		cout << tmp->val << " -> ";
		tmp = tmp->next;
	}
	cout << tmp->val << endl;
}

int main() {
	int testcases;
	cin >> testcases;

	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		ListNode* head = NULL;
		for (int i = 0; i < n; i++) {
			int x; cin>> x;
			addNodeToEnd(head, x);
		}

		Solution s;
		ListNode* reversedHead = s.reverseList(head);
		printLinkedList(reversedHead);
	}
	return 0;
}
