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
        int result = findMin(input, n);
		printf("%d\n", result);
	}
	return 0;
}
