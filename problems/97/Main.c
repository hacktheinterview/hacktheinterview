#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

//-int* repeatedNumber(const int* A, int n) {
//-}

//--SPLIT--
int* repeatedNumber(const int* A, int n) {
	return A;
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
		int * result = repeatedNumber(A, n);
		for (i = 0; i < 1; i++) {
			printf("%d %d ", result[0], result[1]);
		}
		printf("\n");
	}
	return 0;
}
