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
