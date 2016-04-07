// Definition of Linked List Node
// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// 	public:
// 		ListNode* reverseList(ListNode* );
// };
// Please Refrain from using print statements
int findLength(ListNode* H1) {
    ListNode* tmp = H1;
    int len = 0;
    while(tmp != NULL) {
        tmp = tmp->next;
        len++;
    }
    return len;
}

ListNode* addTwoLists(ListNode* H1, ListNode* H2, int diff, int *carry) {
    if (H1 == NULL && H2 == NULL) {
        *carry = 0;
        return NULL;
    }

    if (diff > 0) {
        ListNode* tmp = addTwoLists(H1->next, H2, diff-1, carry);
        int sum = (H1 -> val) + *carry;
        *carry = sum / 10;
        H1->val = sum % 10;
        H1->next = tmp;
        return H1;
    } else {
        ListNode* tmp = addTwoLists(H1->next, H2->next, diff, carry);
        int sum = (H1->val) + (H2->val) + *carry;
        *carry = sum / 10;
        H1->val = sum % 10;
        H1->next = tmp;
        return H1;
    }
    return NULL;
}

ListNode* addTwoLinkedLists(ListNode* H1, ListNode* H2) {
    if (!H1 && !H2) return NULL;
    if (!H1) return H2;
    if (!H2) return H1;
	// Implement the function
    int len1 = findLength(H1);
    int len2 = findLength(H2);

    // Always keep longer list in H1
    if (len2 > len1) {
        ListNode* tmp = H2;
        H2 = H1;
        H1 = tmp;
    }

    int carry = 0;
    ListNode* tmp = addTwoLists(H1, H2, abs(len1 - len2), &carry);
    if (carry > 0) {
        ListNode* head = (ListNode*) malloc(sizeof(ListNode));
        head->val = carry;
        head->next= tmp;
        return head;
    }
    return tmp;
}
