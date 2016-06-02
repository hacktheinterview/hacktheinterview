void preorder(TreeNode* root, vector<int>& result) {
    if (!root)
        return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}
