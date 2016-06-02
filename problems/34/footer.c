char* toStr(int num) {
	char* token;
	sprintf(token,"%d", num);
	return token;
}

int toInt(char token[20]) {
	int num;
	sscanf(token, "%d", &num);
	return num;
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

void printArray(int* result, int len) {
	if (len == 0) {
		printf("\n");
		return;
	}
	int i = 0;
	for (i = 0; i < len - 1; i++)
		printf("%d ", result[i]);
	printf("%d\n", result[len-1]);
}

int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n;
		scanf("%d", &n);
		char tokens[n][20];
		int i = 0;
		for (i = 0; i < n; i++)
			scanf("%s", tokens[i]);

		TreeNode *root = deserializeTree(tokens, n);
		int length = 0;
        int* result = postorderTraversal(root, &length);
		printArray(result, length);
	}
	return 0;
}
