TreeNode* solve(const vector<int>& inorder, const vector<int>& postorder,
		int inStart, int inEnd, int postStart, int postEnd, map<int, int>& M) {

	if (inStart > inEnd || postStart > postEnd) {
		return NULL;
	}

	int curval = postorder[postEnd];
	TreeNode* root = new TreeNode(curval);
	int inorderPos = M[curval];

	root->left = solve(inorder, postorder, inStart, inorderPos - 1, postStart, postStart + inorderPos - (inStart + 1), M);
	root->right = solve(inorder, postorder, inorderPos + 1, inEnd, postStart + inorderPos - inStart, postEnd - 1, M);
	return root;
}

TreeNode* Solution::constructBinaryTree(const vector<int>& inorder,
										const vector<int>& postorder) {
	map<int, int> M;
	for (int i = 0; i < inorder.size(); i++) {
		M[inorder[i]] = i;
	}
	int currentIndex = 0;
	TreeNode* root = solve(inorder, postorder, 0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1, M);
	return root;
}
