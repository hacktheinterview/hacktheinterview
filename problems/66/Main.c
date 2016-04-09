#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input a : Integer
 *
 * @Output Integer
 */
//-int trailingZeroes(int a) {
//-}


//--SPLIT--
int trailingZeroes(int a) {
	int result = 0;
    while (a > 0) {
        result += a/5;
        a /= 5;
    }
    return result;
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
		printf("%d\n", trailingZeroes(a));
	}
	return 0;
}
