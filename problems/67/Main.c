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
//-int gcd(int a, int b) {
//-}


//--SPLIT--
int gcd(int a, int b) {
	if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
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
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
