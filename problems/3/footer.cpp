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

void printInteger(int x) {
	cout<<x<<endl;
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
		int ret = s.isPalindromicList(head);
		printInteger(ret);
	}
	return 0;
}
