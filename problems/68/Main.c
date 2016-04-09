#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input A : Integer
 *
 * @Output Integer
 */
//-int reverse(int A) {
//-}


//--SPLIT--
int reverse(int a) {
	return a;
}


//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", reverse(a));
	}
	return 0;
}
