#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
//-int maxSubArray(const int* A, int n) {
//-}

//--SPLIT--
int maxSubArray(const int* A, int n1) {
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
		printf("%d\n", maxSubArray(A, n));
	}
	return 0;
}
