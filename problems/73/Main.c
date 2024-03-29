#include <stdio.h>
#include <stdlib.h>

//--SPLIT--

/**
 * @input a : Integer
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
//-int* primesum(int a) {
//-}


//--SPLIT--
int * primesum(int a) {
    int result[2];
    int * isPrime = malloc(sizeof(int) * (a + 1));
    for (int i = 2; i <= a; i++) {
            isPrime[i] = 1;
    }
    for(int i = 2; i <=a; i++) {
        for (int j = 2; i * j <= a; j++) {
            isPrime[i * j] = 0;
        }
    }

    for (int i = 2; i < a; i++) {
        int j = a - i;
        if (isPrime[i] == 1 && isPrime[j] == 1) {
            result[0] = i;
            result[1] = j;
            return result;
        }
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
		int* result = primesum(a);
		printf("[%d, %d]\n", result[0], result[1]);
	}
	return 0;
}
