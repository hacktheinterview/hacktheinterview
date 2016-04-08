ListNode* partitionLinkedList(ListNode* head, int N) {
    if (!head) {
        return NULL;
    }

    ListNode *p = (ListNode*) malloc(sizeof(ListNode));
    p->val = 0;
    p->next = head;
    head = p;
    ListNode *last=head;

    if (head->next == NULL) {
        return head->next;
    }

    int n = 0;
    while (last->next != NULL) {
        last=last->next; n++;
    }

    while (n > 0) {
        if (p->next->val < N) {
            p=p->next;
            n--;
        } else {
            ListNode* tmpNode = (ListNode*) malloc(sizeof(ListNode));
            tmpNode->val = p->next->val;
            tmpNode->next = NULL;

            last->next = tmpNode;
            last = last->next;
            p->next = p->next->next;
            n--;
        }
    }
    return head->next;
}
