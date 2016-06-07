// A tree with 100000 elements each element can have 11 characters if it fits in an int
// 10 character + 1 sign character
// this will have space as well and # as well.
// How many bytes we need here? at max 4 * nodes * 12 bytes
int MAX_BYTES_IN_TREE = 5000000;
int toInt(char token[20]) {
	int num;
	sscanf(token, "%d", &num);
	return num;
}

void serializeTree(TreeNode* root, char** str) {
    if (!root) {
        int chars = sprintf(*str, "# ");
		*str = *str + chars;
		return;
    }
	int chars = sprintf(*str, "%d ", root->val);
	*str = *str + chars;
    serializeTree(root->left, str);
    serializeTree(root->right, str);
}

void printSerializeTree(TreeNode* root) {
	char tree[MAX_BYTES_IN_TREE];
	char* current = tree;
	serializeTree(root, &current);
	puts(tree);
}

TreeNode* deserialize(char tokens[][20], int* index, int n) {
    if (*index >= n)
        return NULL;

	int prevIndex = *index;
	*index = *index + 1;

    if (strcmp(tokens[prevIndex], "#") == 0) {
        return NULL;
    }

    TreeNode* root = (TreeNode*) malloc(sizeof (TreeNode));
	root->val = toInt(tokens[prevIndex]);
    root->left = deserialize(tokens, index, n);
    root->right = deserialize(tokens, index, n);
    return root;
}

TreeNode* deserializeTree(char tokens[][20], int n) {
    int index = 0;
    return deserialize(tokens, &index, n);
}

int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n;
		scanf("%d", &n);
		int inorder[n];
        int postorder[n];
        int i = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &inorder[i]);

		for (i = 0; i < n; i++)
			scanf("%d", &postorder[i]);

        TreeNode* root = constructBinaryTree(n, inorder, postorder);
		printSerializeTree(root);
	}
	return 0;
}
