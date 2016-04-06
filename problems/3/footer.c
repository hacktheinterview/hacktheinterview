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

void printInteger(int x) {
	printf("%d\n", x);
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
		int n;
		scanf("%d", &n);
		ListNode* head = NULL;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			addNodeToEnd(&head, x);
		}
		int val = isPalindromicList(head);
        printInteger(val);
	}
	return 0;
}
