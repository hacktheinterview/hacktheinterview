#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//--SPLIT--

/**
 * @input A : Integer
 *
 * @Output Integer 0 / 1. 0 if false, 1 if true.
 */
//-int isPower(int A) {
//-}


//--SPLIT--
int isPower(int a) {
	if (a == 1) {
       return 1;
    }
    int x, y;
    for (x = 2; x <= sqrt(a); x++) {
        for (y = 2; pow(x, y) <= a; y++) {
            if (pow(x, y) == a)
                return 1;
        }
    }
    return 0;
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
		int result = isPower(a);
		printf("%d\n", isPower(a));
	}
	return 0;
}
