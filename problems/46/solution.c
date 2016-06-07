// struct node {
// 	  int val;
// 	  struct node* left;
//    struct node* right;
// };
// typedef struct node TreeNode;

// Please refrain from using print statements

int search(int* arr, int strt, int end, int value) {
    int i;
    for(i = strt; i <= end; i++) {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

struct node* buildTree(int* preorder, int* inorder, int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */

    TreeNode* root = (TreeNode*) malloc(sizeof (TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = preorder[*preIndex];
    *preIndex = *preIndex + 1;
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return root;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(inorder, inStrt, inEnd, root->val);

    /* Using index in Inorder traversal, construct left and
        right subtress */
    root->left = buildTree(preorder, inorder, inStrt, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}


TreeNode* constructBinaryTree(int n, int* preorder, int* inorder) {
    // Implement the function
    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);
    return root;
}
