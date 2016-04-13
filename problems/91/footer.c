
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n, i, j;
		int **A;
		int ** result = diagonal(A);
		for (i = 0; i < n; i++) {
			int * v = result[i];
			for (j = 0; j <= i; j++) {
				printf("%d ", v[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
