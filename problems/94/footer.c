
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int A, i;
		scanf("%d", &A);
		int * result = getRow(A);
		for (i = 0; i < A + 1; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	return 0;
}
