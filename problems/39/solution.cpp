// 	 struct TreeNode {
// 	     string val;
// 	     TreeNode* left;
//       TreeNode* right;
//       TreeNode(string x): val(x), left(NULL), right(NULL) {}
//   };
//
//   class Solution {
// 	   public:
// 		  int isPairPresent(TreeNode* tree, int K);
//   };
//
//   Please refrain from using print statements

void inorder(TreeNode* root, vector<int>& order) {
    if (!root)
        return;
    inorder(root->left, order);
    order.push_back(root->val);
    inorder(root->right, order);
}

int hasTwoSum(const vector<int>& order, int K) {
    if (order.size() <= 1)
        return 0;
    int start = 0, end = (int)order.size() - 1;
    while (start < end) {
        if (order[start] + order[end] == K)
            return 1;
        if (order[start] + order[end] > K)
            end --;
        else
            start++;
    }
    return 0;
}

int Solution::isPairPresent(TreeNode* root, int K) {
    if (!root) {
        return 0;
    }

    vector<int> order;
	inorder(root, order);
	return hasTwoSum(order, K);
}
