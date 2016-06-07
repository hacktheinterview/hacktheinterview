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
		TreeNode* constructBinaryTree(const vector<int>& inorder,
									  const vector<int>& postorder);
};


// 	 struct TreeNode {
// 	     string val;
// 	     TreeNode* left;
//       TreeNode* right;
//       TreeNode(string x): val(x), left(NULL), right(NULL) {}
//   };
//
//   class Solution {
// 	   public:
// 		  TreeNode* constructBinaryTree(const vector<int>& inorder,
// 		  								const vector<int>& postorder);
//   };
//
//   Please refrain from using print statements

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
