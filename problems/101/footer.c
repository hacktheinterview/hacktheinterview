int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		unsigned int n;
		scanf("%u", &n);
        int result = isPalindrome(n);
		printf("%d\n", result);
	}
	return 0;
}
