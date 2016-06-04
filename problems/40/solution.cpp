// 	 struct TreeNode {
// 	     string val;
// 	     TreeNode* left;
//       TreeNode* right;
//       TreeNode(string x): val(x), left(NULL), right(NULL) {}
//   };
//
//   class Solution {
// 	   public:
// 		  int KthSmallest(TreeNode* tree, int K);
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

int Solution::KthSmallest(TreeNode* root, int K) {
    if (!root) {
        return 0;
    }

    vector<int> order;
	inorder(root, order);
    return order[K-1];
}
