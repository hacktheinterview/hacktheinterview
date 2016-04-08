#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input A : Integer
 *
 * @Output string. Make sure the string ends with null character
 */
//-char* convertToTitle(int A) {
	// SAMPLE CODE
	/*
	 * char *result = (char *)malloc(100 * sizeof(char));
	 * // DO STUFF
	 * return result;
	 */
//-}


//--SPLIT--
char* convertToTitle(int a) {
	char *result = (char *)malloc(100 * sizeof(char));
	while (a > 0) {
        int r = (a - 1) % 26;
         result = (char) ('A' + r) + result;
        a = (a - 1) / 26;
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
		printf("%s\n", convertToTitle(a));
	}
	return 0;
}
