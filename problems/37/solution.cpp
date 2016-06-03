void solve(TreeNode* root, int level, int& ret) {
    if (!root) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        ret = min(ret, level);
    }

    solve(root->left, level + 1, ret);
    solve(root->right, level + 1, ret);
}

int Solution::minDepth(TreeNode* root) {
    if (!root)
        return 0;

    int ret = INT_MAX;
	solve(root, 1, ret);
	return ret;
}
