#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input a : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
//-char* countAndSay(int a) {
//-}

//--SPLIT--
char* countAndSay(int a) {
	return "";
}



//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n, i; scanf("%d", &n);
		printf("%s\n", countAndSay(n));
	}
	return 0;
}
