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
		int isValidBinarySearchTree(TreeNode* root);
};
// struct TreeNode {
// 	string val;
// 	TreeNode* left;
//     TreeNode* right;
//     TreeNode(string x): val(x), left(NULL), right(NULL) {}
// };
//
// class Solution {
// 	public:
// 		TreeNode* isValidBinarySearchTree(TreeNode* tree);
// };
// Please Refrain from using print statements
int isBST(TreeNode* root, int mini, int maxi) {
    if (!root) return 1;
    if (root->val < mini || root->val > maxi) return 0;
    return isBST(root->left, mini, root->val - 1) &&
           isBST(root->right, root->val + 1, maxi);
}

int Solution::isValidBinarySearchTree(TreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}


string toStr(int x) {
    stringstream s;
    s<<x;
    return s.str();
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void preorder(TreeNode* root, stringstream& ss) {
    if (!root) {
        ss << ("#") << " ";
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

    TreeNode* root = new TreeNode(toInt(val));
    root->left = deserialize(tokens, index);
    root->right = deserialize(tokens, index);
    return root;
}

TreeNode* deserializeTree(const vector<string>& tokens) {
    int index = 0;
    auto root = deserialize(tokens, index);
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
