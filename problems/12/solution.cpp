// Definition of Linked List Node
// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// 	public:
// 		ListNode* mergeTwoSortedLinkedListsInReverse(ListNode*, ListNode*);
// };
// Please Refrain from using print statements

ListNode* mergeTwoSortedLinkedListsInReverseUtil(ListNode* H1, ListNode* H2, ListNode* &ret) {
    if (H1 == NULL && H2 == NULL) {
        return NULL;
    }

    if (H1 && !H2) {
        ret = H1;
        ListNode* result = mergeTwoSortedLinkedListsInReverseUtil(H1->next, H2, ret);
        if (result) {
            result->next = H1;
        }
        H1->next = NULL;
        return H1;
    }

    if (H2 && !H1) {
        ret = H2;
        ListNode* result = mergeTwoSortedLinkedListsInReverseUtil(H1, H2->next, ret);
        if (result) {
            result->next = H2;
        }
        H2->next = NULL;
        return H2;
    }

    if (H1-> val > H2->val) {
        ListNode* result = mergeTwoSortedLinkedListsInReverseUtil(H1, H2->next, ret);
        if (result)
            result->next = H2;
        H2->next = NULL;
        return H2;
    } else {
        ListNode* result = mergeTwoSortedLinkedListsInReverseUtil(H1->next, H2, ret);
        if (result)
            result->next = H1;
        H1->next = NULL;
        return H1;
    }
}

ListNode* Solution::mergeTwoSortedLinkedListsInReverse(ListNode* H1,
            ListNode* H2) {

    ListNode* ret = NULL;
    ListNode* tail = mergeTwoSortedLinkedListsInReverseUtil(H1, H2, ret);
    return ret;
}
