int isMirror(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return 1;

    if (root1 && root2 && root1->val == root2->val)
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);

    return 0;
}

int Solution::isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}
