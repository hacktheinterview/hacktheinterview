#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

//-int ** generate(int A, int *number_of_rows) {
//-}

//--SPLIT--
int ** generate(int A) {
	int ** result;
	return result;
}

//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int A, i, j;
		scanf("%d", &A);
		int ** result = generate(A);
		for (i = 0; i < A; i++) {
			int * v = result[i];
			for (j = 0; j <= i; j++) {
				printf("%d ", v[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
