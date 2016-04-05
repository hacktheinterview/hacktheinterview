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
		int n1; cin >> n1;
		ListNode* H1 = NULL;
		for (int i = 0; i < n1; i++) {
			int x; cin>> x;
			addNodeToEnd(H1, x);
		}

        int n2; cin >> n2;
		ListNode* H2 = NULL;
		for (int i = 0; i < n2; i++) {
			int x; cin>> x;
			addNodeToEnd(H2, x);
		}

		Solution s;
		ListNode* resultList = s.mergeTwoSortedLinkedLists(H1, H2);
		printLinkedList(resultList);
	}
	return 0;
}
