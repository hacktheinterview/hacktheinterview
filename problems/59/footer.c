
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n, i; scanf("%d", &n);
		printf("%s\n", countAndSay(n));
	}
	return 0;
}
