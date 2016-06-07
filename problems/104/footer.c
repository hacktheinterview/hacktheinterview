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
		int n; scanf("%d", &n);
        int input[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &input[i]);
        }
        int K; scanf("%d", &K);
        int* result = sortNearlySortedArray(input, n, K);
		printArray(result, K);
	}
	return 0;
}
