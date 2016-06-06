TreeNode* solve(TreeNode* root, int A, int B, bool& foundA, bool& foundB) {
	if (!root) {
		return NULL;
	}

	if (root->val == A)
		foundA = true;
	if (root->val == B)
		foundB = true;


	TreeNode* left = solve(root->left, A, B, foundA, foundB);
	TreeNode* right = solve(root->right, A, B, foundA, foundB);

	if ((left && right) || root->val == A || root->val == B)
		return root;

	return left? left: right;
}

int Solution::lca(TreeNode* root, int A, int B) {
	if (!root)
		return -1;

	bool foundA = false, foundB = false;
	auto node = solve(root, A, B, foundA, foundB);
	if (foundA && foundB)
		return node->val;
	return -1;
}
