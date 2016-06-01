#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int solve(TreeNode* root, int* ret) {
    if (!root)
        return 0;

    int lRet = 1, rRet = 1;
    int lHeight = solve(root->left, &lRet);
    int rHeight = solve(root->right, &rRet);

    if (abs(lHeight - rHeight) > 1) {
        *ret = 0;
    }
    *ret = *ret && lRet && rRet;
    return MAX(lHeight, rHeight) + 1;
}

int isBalanced(TreeNode* root) {
	// Implement the solution
	int ret = 1;
	solve(root, &ret);
	return ret;
}
