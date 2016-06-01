// struct TreeNode {
// 	string val;
// 	TreeNode* left;
//     TreeNode* right;
//     TreeNode(string x): val(x), left(NULL), right(NULL) {}
// };
//
// class Solution {
// 	public:
// 		TreeNode* isValidBinarySearchTree(TreeNode* tree);
// };
// Please Refrain from using print statements
int isBST(TreeNode* root, int mini, int maxi) {
    if (!root) return 1;
    if (root->val < mini || root->val > maxi) return 0;
    return isBST(root->left, mini, root->val - 1) &&
           isBST(root->right, root->val + 1, maxi);
}

int Solution::isValidBinarySearchTree(TreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}
