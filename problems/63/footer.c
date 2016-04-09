
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n, i;
		scanf("%d", &n);
		int *a = (int *)malloc(sizeof(int)* n);;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		arrange(a, n);
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}
