#include <stdio.h>
#include <stdlib.h>
struct node {
	int val;
	struct node* next;
};
typedef struct node ListNode;

ListNode* removeDuplicates(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* current = head;
	ListNode* next = current->next;

	int dup = 0;
	while (next && next->val == current->val) {
		dup = 1;
		next = next->next;
	}

	if (dup == 1) {
		return removeDuplicates(next);
	} else {
		current->next = removeDuplicates(next);
		return current;
	}
}

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
		int n;
		scanf("%d", &n);
		ListNode* head = NULL;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			addNodeToEnd(&head, x);
		}

		ListNode* newHead = removeDuplicates(head);
		printLinkedList(newHead);
	}
	return 0;
}
