#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input A : String termination by '\0'
 *
 * @Output Integer
 */
//-int titleToNumber(char* a) {
//-}


//--SPLIT--
int titleToNumber(char* a) {
	int result = 0;
    for (int i = 0; i < strlen(a); i++) {
        char c = a[strlen(a) - i - 1];
        result += ((int)c - 'A' + 1) * pow(26, i);
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
		char a[256];
		scanf("%s", a);
		printf("%d\n", titleToNumber(a));
	}
	return 0;
}
