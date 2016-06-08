ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
	if (!a) return b;
	if (!b) return a;
	if (a->val < b->val) {
		a->next = mergeTwoLists(a->next, b);
		return a;
	} else {
		b->next = mergeTwoLists(a, b->next);
		return b;
	}
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) {
		return NULL;
	}

	queue<ListNode*> Q;
	for (int i = 0; i < lists.size(); i++) {
		Q.push(lists[i]);
	}

	while(!Q.empty()) {
		ListNode* first = Q.front(); Q.pop();
		if (Q.empty()) return first;
		ListNode* second = Q.front(); Q.pop();
		ListNode* mergedList = mergeTwoLists(first, second);
		Q.push(mergedList);
	}
}
