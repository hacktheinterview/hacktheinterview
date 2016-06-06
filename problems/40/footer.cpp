string toStr(int x) {
    stringstream s;
    s<<x;
    return s.str();
}

void preorder(TreeNode* root, stringstream& ss) {
    if (!root) {
        ss << ("null") << " ";
        return;
    }
    ss << (toStr(root->val)) << " ";
    preorder(root->left, ss);
    preorder(root->right, ss);
}

string serializeTree(TreeNode* root) {
    stringstream ss;
    preorder(root, ss);
    string ret = ss.str();
    return ret;
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
        vector<string> inputItems(n);
        for (int i = 0; i < n; i++) {
            cin >> inputItems[i];
        }
        int K; cin >> K;
        TreeNode *root = deserializeTree(inputItems);
        Solution s;
        int result = s.KthSmallest(root, K);
        cout << result << endl;
	}
	return 0;
}
