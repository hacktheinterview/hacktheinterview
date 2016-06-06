// 	 struct TreeNode {
// 	     string val;
// 	     TreeNode* left;
//       TreeNode* right;
//       TreeNode(string x): val(x), left(NULL), right(NULL) {}
//   };
//
//   class Solution {
// 	   public:
// 		  vector<vector<int>> zigzagLevelOrder(TreeNode* root);
//   };
//
//   Please refrain from using print statements

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    stack<TreeNode*> S1, S2;
    S1.push(root);
	int level = 0;
    while (!S1.empty()) {
        vector<int> row;
		level++;
        while (!S1.empty()) {
            auto currentNode = S1.top(); S1.pop();
            row.push_back(currentNode->val);
			if (level % 2 == 1) {
	            if (currentNode -> left)
	                S2.push(currentNode->left);
	            if (currentNode -> right)
	                S2.push(currentNode -> right);
			} else {
				if (currentNode -> right)
					S2.push(currentNode -> right);
				if (currentNode -> left)
					S2.push(currentNode->left);
			}
        }
        S1 = S2;
        S2 = stack<TreeNode*> ();
        result.push_back(row);
    }
    return result;

}
