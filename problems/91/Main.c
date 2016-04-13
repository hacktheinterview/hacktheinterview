#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, and first entry in result array must be size of that row.  
 */
//-int ** diagonal(int** A) {
//-}


//--SPLIT--
int ** diagonal(int** A) {
	return A;
}

//--SPLIT--
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
