void solve(TreeNode* root, int& ret, int cursum) {
    if (!root)
        return;

    cursum += root->val;

    if (root->left == NULL && root->right == NULL) {
        ret = max(ret, cursum);
        return;
    }
    solve(root->left, ret, cursum);
    solve(root->right, ret, cursum);
}

int Solution::maxSumPathRootToLeaf(TreeNode* root) {
    if (!root)
        return 0;

    int ret = INT_MIN;
    solve(root, ret, 0);
    return ret;
}
