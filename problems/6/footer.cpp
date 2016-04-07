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
		int numNodes; cin >> numNodes;
		ListNode* head = NULL;
		for (int i = 0; i < numNodes; i++) {
			int x; cin>> x;
			addNodeToEnd(head, x);
		}
		int n; cin>>n;
		Solution s;
		ListNode* newHead = s.removeNthNodeFromList(head, n);
		printLinkedList(newHead);
	}

	return 0;
}
