
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", trailingZeroes(a));
	}
	return 0;
}
