
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char* a[1024]; scanf(" %[^\n]s", a);
		reverseWords(a);
		printf("%s\n", a);
	}
	return 0;
}
