
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int a;
		scanf("%d", &a);
		int result = isPower(a);
		printf("%d\n", isPower(a));
	}
	return 0;
}
