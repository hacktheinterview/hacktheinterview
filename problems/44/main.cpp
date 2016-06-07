#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int lca(TreeNode* root, int A, int B);
};

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
        int A, B;
        cin >> A >> B;
        TreeNode *root = deserializeTree(inputItems);
        Solution s;
        auto result = s.lca(root, A, B);
        cout << result << endl;
	}
	return 0;
}
