// struct node {
// 	  int val;
// 	  struct node* left;
//    struct node* right;
// };
// typedef struct node TreeNode;

// Please refrain from using print statements

const int MAXN = 100000;

void inorder(TreeNode* root, int* result, int* length) {
    if (!root)
        return;
    inorder(root->left, result, length);
    result[*length] = root->val;
    *length = *length + 1;
    inorder(root->right, result, length);
}

int* inorderTraversal(TreeNode* root, int* length) {
    int* result = (int*) malloc((sizeof (int)) * MAXN);
    *length = 0;
    inorder(root, result, length);
    return result;
}
