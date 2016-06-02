// struct node {
// 	  int val;
// 	  struct node* left;
//    struct node* right;
// };
// typedef struct node TreeNode;

// Please refrain from using print statements

const int MAXN = 100000;

void preorder(TreeNode* root, int* result, int* length) {
    if (!root)
        return;
    result[*length] = root->val;
    *length = *length + 1;
    preorder(root->left, result, length);
    preorder(root->right, result, length);
}

int* preorderTraversal(TreeNode* root, int* length) {
    int* result = (int*) malloc((sizeof (int)) * MAXN);
    *length = 0;
    preorder(root, result, length);
    return result;
}
