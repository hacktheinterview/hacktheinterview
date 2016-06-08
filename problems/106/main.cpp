#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists);
};

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
    for (int i = 0; i < lists.size(); i++) Q.push(lists[i]);
    ListNode* last = NULL;
    while(!Q.empty()) {
        ListNode* first = Q.front(); Q.pop();
        if (Q.empty()) return first;
        ListNode* second = Q.front(); Q.pop();
        ListNode* mergedList = mergeTwoLists(first, second);
        Q.push(mergedList);
        last = mergedList;
    }
    return last;
}

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
		int n; cin >> n;
		vector<ListNode*> lists;

		for (int i = 0; i < n; i++) {
			int m; cin >> m;
			ListNode* head = NULL;
			for (int j = 0; j < m; j++) {
				int x; cin>> x;
				addNodeToEnd(head, x);
			}
			lists.push_back(head);
		}

		Solution s;
		ListNode* mergedHead = s.mergeKLists(lists);
		printLinkedList(mergedHead);
	}
	return 0;
}
