#include <stdio.h>
#include <stdlib.h>
struct node {
	int val;
	struct node* next;
};
typedef struct node ListNode;
// Definition of Linked List Node
// struct node {
// 	int val;
// 	struct node* next;
// };
// typedef struct node ListNode;
// Please refrain from using print statements

ListNode* mergeKLists(ListNode** lists, int listsSize) {
	return NULL;
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
		int numLists;
		scanf("%d", &numLists);

		ListNode* lists[numLists];

		int i = 0;
		for (i = 0; i < numLists; i++) {
			int numNodes;
			scanf("%d", &numNodes);
			int j;
			ListNode* head = NULL;
			for (j = 0; j < numNodes; j++) {
				int x; scanf("%d\n", &x);
				addNodeToEnd(&head, x);
			}
			lists[i] = head;
		}

		ListNode* mergedHead = mergeKLists(lists, numLists);
		printLinkedList(mergedHead);
	}
	return 0;
}
