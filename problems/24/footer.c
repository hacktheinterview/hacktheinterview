int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n; scanf("%d", &n);
		int result = squareRoot(n);
		printf("%d\n", result);
	}
	return 0;
}
