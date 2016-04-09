void addNodeToEnd(ListNode** head, int val) {
	ListNode* tmp = (ListNode*) malloc(sizeof(ListNode));
	tmp->val = val;
	tmp->next = NULL;

	if (*head == NULL) {
		*head = tmp;
		(*head)->next = NULL;
	} else {
		ListNode* tail = *head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = tmp;
	}
}

void printLinkedList(ListNode* head) {
	if (!head) {
		printf("\n");
		return;
	}
	ListNode* tmp = head;
	while(tmp->next != NULL) {
		printf("%d -> ", tmp->val);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->val);
}

int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int numNodes;
		scanf("%d", &numNodes);
		ListNode* head = NULL;
		for (int i = 0; i < numNodes; i++) {
			int x;
			scanf("%d", &x);
			addNodeToEnd(&head, x);
		}
		int M; scanf("%d", &M);
		int N; scanf("%d", &N);
        ListNode* newHead = reverseNodesFromMtoN(head, M, N);
		printLinkedList(newHead);
	}
	return 0;
}
