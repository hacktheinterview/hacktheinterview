#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int height(TreeNode* root) {
    if (!root)
        return 0;
    return MAX(height(root->left), height(root->right)) + 1;
}
