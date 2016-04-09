#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input a : String termination by '\0'
 *
 * @Output Integer
 */
//-int findRank(char* a) {
//-}


//--SPLIT--
int findRank(char* a) {
	return 0;
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
		printf("%d\n", findRank(a));
	}
	return 0;
}
