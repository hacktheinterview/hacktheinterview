#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

//-int* plusOne(int* A, int n) {
//-}

//--SPLIT--
int* maxset(int* A, int n) {
	return 0;
}

//--SPLIT--
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
