
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char s[256];
		scanf(" %[^\n]s",s);
		printf("%d\n", isPalindrome(s));
	}
	return 0;
}
