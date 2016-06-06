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
		vector<vector<int>> levelOrder(TreeNode* root);
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
// 		  vector<vector<int>> levelOrder(TreeNode* root);
//   };
//
//   Please refrain from using print statements

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    queue<TreeNode*> Q1, Q2;
    Q1.push(root);
    while (!Q1.empty()) {
        vector<int> row;
        while (!Q1.empty()) {
            auto currentNode = Q1.front(); Q1.pop();
            row.push_back(currentNode->val);
            if (currentNode -> left)
                Q2.push(currentNode->left);
            if (currentNode -> right)
                Q2.push(currentNode -> right);
        }
        Q1 = Q2;
        Q2 = queue<TreeNode*> ();
        result.push_back(row);
    }
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
        auto result = s.levelOrder(root);
        print2DVector(result);
	}
	return 0;
}
