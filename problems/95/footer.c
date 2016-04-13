
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n, i;
		scanf("%d", &n);
		int *A = malloc (sizeof (int) * n);
		for (i = 0; i < n; i++)  {
			scanf("%d", &A[i]);
		}
		int * result = maxset(A, n);
		for (i = 0; i < n; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	return 0;
}
