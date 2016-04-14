string tostr(int x) {
    if (x == 0) return "0";
    string ret = "";
    int neg = 0;
    if (x < 0) {
        neg = 1;
        x = -x;
    }

    while(x) {
        int mod = x % 10;
        ret += (mod + '0');
        x = x/10;
    }
    reverse(ret.begin(), ret.end());
    if (neg) return "-" + ret;
    return ret;
}

void printTreeToOutputFormat(TreeNode* root) {
    vector<string> ret;
    if (!root) {
        cout << endl;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* tmp = q.front(); q.pop();
        if (!tmp) {
            ret.push_back("#");
            continue;
        }
        ret.push_back(tostr(tmp->val));

        q.push(tmp->left);
        q.push(tmp->right);
    }
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i != ret.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int toint(string x) {
    if (x.size() == 0) return 0;
    int start = 1;
    int ret = 1;
    if (x[0] == '-') {
        ret = x[1] - '0';
        ret = -ret;
        start = 2;
    } else {
        ret = x[0] - '0';
    }
    for (int i = start; i < x.size(); i++) {
        ret = ret * 10 + x[i] - '0';
    }
    return ret;
}

TreeNode* deserializeTree(const vector<string>& inputItems) {
    if (inputItems.size() == 0) return NULL;
    // make it integer.
    TreeNode* root = new TreeNode(toint(inputItems[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;

    while (index < inputItems.size()) {
        TreeNode* tmp = q.front();
        q.pop();

        if (inputItems[index] == "#") {
            tmp->left = NULL;
        } else {
            int val = toint(inputItems[index]);
            TreeNode* leftNode = new TreeNode(val);
            tmp->left = leftNode;
            q.push(leftNode);
        }
        index++;

        if (inputItems[index] == "#") {
            tmp->right = NULL;
        } else {
            int val = toint(inputItems[index]);
            TreeNode* rightNode = new TreeNode(val);
            tmp->right = rightNode;
            q.push(rightNode);
        }
        index++;
    }
    return root;
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
        TreeNode *root = deserializeTree(inputItems);
        Solution s;
        int result = s.isValidBinarySearchTree(root);
        cout << result << endl;
	}
	return 0;
}
