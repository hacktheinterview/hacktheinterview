void addNodeToEnd(ListNode** head, int val) {
	ListNode* tmp = (ListNode*) malloc(sizeof(ListNode));
	tmp->val = val;

	if (*head == NULL) {
		*head = tmp;
	} else {
		ListNode* tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = tmp;
	}
    return;
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

        int n1; scanf("%d", &n1);
		ListNode* H1 = NULL;

		for (int i = 0; i < n1; i++) {
			int x; scanf("%d", &x);
			addNodeToEnd(&H1, x);
		}

        int n2; scanf("%d", &n2);

		ListNode* H2 = NULL;
		for (int i = 0; i < n2; i++) {
			int x; scanf("%d", &x);
			addNodeToEnd(&H2, x);
		}

		ListNode* mergedList = mergeTwoSortedLinkedLists(H1, H2);
		printLinkedList(mergedList);
	}
	return 0;
}
