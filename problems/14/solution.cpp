ListNode* Solution::partitionLinkedList(ListNode* head, int N) {
    if (!head) {
        return NULL;
    }

    ListNode *p= new ListNode(0);
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
            last->next = new ListNode(p->next->val);
            last = last->next;
            p->next = p->next->next;
            n--;
        }
    }
    return head->next;
}
