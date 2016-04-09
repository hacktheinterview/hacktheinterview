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
//-int isPalindrome(char* a) {
//-}



//--SPLIT--
int isPalindrome(char* a) {
	return 0;
}


//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char s[256];
		scanf(" %[^\n]s",s);
		printf("%d\n", isPalindrome(s));
	}
	return 0;
}
