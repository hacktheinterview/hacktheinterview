int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int rows, cols;
		scanf("%d %d", &rows, &cols);
		int input[rows][cols];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				scanf("%d", &input[i][j]);
			}
		}
		int K;
		scanf("%d", &K);
		int result = searchMatrix(input, rows, cols, K);
		printf("%d\n", result);
	}
	return 0;
}
