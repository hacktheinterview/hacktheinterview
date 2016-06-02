#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int diameterHelper(TreeNode* root, int* result) {
    if (!root)
        return 0;

    int lHeight = diameterHelper(root->left, result);
    int rHeight = diameterHelper(root->right, result);

    *result = MAX(*result, rHeight + lHeight + 1);
    return MAX(lHeight, rHeight) + 1;
}

int diameter(TreeNode* root) {
	// Implement the solution
    int result = 0;
    int height = diameterHelper(root, &result);
    return result;
}
