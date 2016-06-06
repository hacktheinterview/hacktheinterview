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

int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n, K;
		scanf("%d", &n);
		char tokens[n][20];
		int i = 0;
		for (i = 0; i < n; i++)
			scanf("%s", tokens[i]);
		scanf("%d", &K);
		TreeNode *root = deserializeTree(tokens, n);
		int result = KthSmallest(root, K);
		printf("%d\n", result);
	}
	return 0;
}
