#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

//-int coverPoints(int* X, int* Y, int n) {
//-}


//--SPLIT--
int coverPoints(int* X, int* Y, int n) {
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
		int *X = malloc (sizeof (int) * n);
		int *Y = malloc (sizeof (int) * n);
		for (i = 0; i < n; i++)  {
			scanf("%d", &X[i]);
		}
		for (i = 0; i < n; i++)  {
			scanf("%d", &Y[i]);
		}
		printf("%d\n", coverPoints(X, Y, n));
	}
	return 0;
}
