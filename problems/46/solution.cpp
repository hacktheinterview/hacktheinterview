TreeNode* solve(const vector<int>& preorder, const vector<int>& inorder, int start, int end, int& currentIndex,
	map<int, int>& M) {
	if (start > end || currentIndex >= preorder.size()) {
		return NULL;
	}

	int curval = preorder[currentIndex++];
	TreeNode* root = new TreeNode(curval);
	root->left = solve(preorder, inorder, start, M[curval] - 1, currentIndex, M);
	root->right = solve(preorder, inorder, M[curval] + 1, end, currentIndex, M);
	return root;
}

TreeNode* Solution::constructBinaryTree(const vector<int>& preorder,
		const vector<int>& inorder) {
	map<int, int> M;
	for (int i = 0; i < inorder.size(); i++) {
		M[inorder[i]] = i;
	}
	int currentIndex = 0;
	TreeNode* root = solve(preorder, inorder, 0, (int)inorder.size() - 1, currentIndex, M);
	return root;
}
