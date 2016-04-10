#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input a : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
//-int lengthOfLastWord(const char* a) {
//-}

//--SPLIT--
int lengthOfLastWord(const char* a) {
	return 0;
}

//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char* a[256]; scanf(" %[^\n]s", a);
		printf("%d\n", lengthOfLastWord(a));
	}
	return 0;
}
