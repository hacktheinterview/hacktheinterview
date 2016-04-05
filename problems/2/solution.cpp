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

ListNode* Solution::mergeTwoSortedLinkedLists(ListNode* H1, ListNode* H2) {
	// Implement the function
    if (!H1) return H2;
    if (!H2) return H1;
    ListNode *tmp = H1;
    if (tmp->val > H2->val) {
        tmp = H2;
        tmp->next = mergeTwoSortedLinkedLists(H1, H2->next);
    } else {
        tmp = H1;
        tmp->next = mergeTwoSortedLinkedLists(H1->next, H2);
    }
    return tmp;
}
