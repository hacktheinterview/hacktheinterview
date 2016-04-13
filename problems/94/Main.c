#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

//-int* plusOne(int* A, int n) {
//-}

//--SPLIT--
int* getRow(int A) {
	int * result = malloc((A + 1) * sizeof(int));
	return result;
}

//--SPLIT--
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
