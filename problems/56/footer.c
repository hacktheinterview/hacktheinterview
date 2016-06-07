int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		unsigned int n;
		scanf("%u", &n);
        unsigned int result = nextHigher(n);
		printf("%u\n", result);
	}
	return 0;
}
