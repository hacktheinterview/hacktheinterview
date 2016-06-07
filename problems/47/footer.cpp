string toStr(int x) {
    stringstream s;
    s<<x;
    return s.str();
}

void serializeTree(TreeNode* root, stringstream& ss) {
    if (!root) {
        ss << ("#") << " ";
        return;
    }
    ss << (toStr(root->val)) << " ";
    serializeTree(root->left, ss);
    serializeTree(root->right, ss);
}

void printSerializeTree(TreeNode* root) {
    stringstream ss;
    serializeTree(root, ss);
    string ret = ss.str();
    cout << ret.substr(0, ret.length() - 1) << endl;
}

int toInt(string x) {
    stringstream s(x);
    int y;
    s>>y;
    return y;
}

TreeNode* deserialize(const vector<string>& tokens, int& index) {
    if (index >= (int)tokens.size())
        return NULL;

    string val = tokens[index];
    index++;
    if (val == "#") {
        return NULL;
    }

    TreeNode * root = new TreeNode(toInt(val));
    root->left = deserialize(tokens, index);
    root->right = deserialize(tokens, index);
    return root;
}

TreeNode* deserializeTree(const vector<string>& tokens) {
    int index = 0;
    return deserialize(tokens, index);
}

int main() {
	int testcases;
	cin >> testcases;

	for (int t = 0; t < testcases; t++) {
        int n; cin >> n;

        vector<int> inorder(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }

        vector<int> postorder(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> postorder[i];
        }

        Solution s;
        auto result = s.constructBinaryTree(inorder, postorder);
        printSerializeTree(result);
	}
	return 0;
}
