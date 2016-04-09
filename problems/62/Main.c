#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input a : Integer
 * @input b : Integer
 * 
 * @Output Integer
 */
//-int uniquePaths(int a, int b) {
//-}


//--SPLIT--
int uniquePaths(int a, int b) {
	return 0;
}


//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", uniquePaths(a, b));
	}
	return 0;
}
