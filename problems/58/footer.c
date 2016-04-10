
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char* a[256]; scanf(" %[^\n]s", a);
		printf("%d\n", lengthOfLastWord(a));
	}
	return 0;
}
