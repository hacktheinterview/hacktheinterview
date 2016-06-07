void solve(TreeNode* root, vector<vector<int>>& result, vector<int>& current) {
	if (!root) {
		return;
	}

	current.push_back(root->val);
	if (root->left == NULL && root->right == NULL) {
		result.push_back(current);
	}
	solve(root->left, result, current);
	solve(root->right, result, current);
	current.pop_back();
	return;
}

vector<vector<int>> Solution::binaryTreePaths(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
	vector<int> current;
	solve(root, result, current);
    return result;
}
