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
		vector<vector<int>> binaryTreePaths(TreeNode* root);
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
// 		  vector<vector<int>> binaryTreePaths(TreeNode* root);
//   };
//
//   Please refrain from using print statements

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

void print2DVector(const vector<vector<int>>& result) {
    cout << "[";
    for (const auto& row: result) {
        cout << "[";
        for (const auto& element: row) {
            cout << element << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
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
        auto result = s.binaryTreePaths(root);
        print2DVector(result);
	}
	return 0;
}
