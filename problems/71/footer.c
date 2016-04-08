
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char a[256];
		scanf("%s", a);
		printf("%d\n", titleToNumber(a));
	}
	return 0;
}
