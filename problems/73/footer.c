
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int a;
		scanf("%d", &a);
		int* result = primesum(a);
		printf("[%d, %d]\n", result[0], result[1]);
	}
	return 0;
}
