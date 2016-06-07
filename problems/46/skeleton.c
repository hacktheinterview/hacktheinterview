// struct node {
// 	  int val;
// 	  struct node* left;
//    struct node* right;
// };
// typedef struct node TreeNode;

// Please refrain from using print statements
TreeNode* constructBinaryTree(int n, int* preorder, int* inorder) {
    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);
    return root;
}
