// struct node {
// 	  int val;
// 	  struct node* left;
//    struct node* right;
// };
// typedef struct node TreeNode;

// Please refrain from using print statements

const int MAXN = 100000;

void postorder(TreeNode* root, int* result, int* length) {
    if (!root)
        return;
    postorder(root->left, result, length);
    postorder(root->right, result, length);
    result[*length] = root->val;
    *length = *length + 1;
}

int* postorderTraversal(TreeNode* root, int* length) {
    int* result = (int*) malloc((sizeof (int)) * MAXN);
    *length = 0;
    postorder(root, result, length);
    return result;
}
