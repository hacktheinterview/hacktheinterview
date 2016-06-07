int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int a, b;
		scanf("%d %d", &a, &b);
        int result = divide(a, b);
		printf("%d\n", result);
	}
	return 0;
}
