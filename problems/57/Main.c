#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input a : String termination by '\0'
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
//-void reverseWords(char* a) {
//-}


//--SPLIT--
void reverseWords(char* a) {
	return;
}

//--SPLIT--
int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		char* a[1024]; scanf(" %[^\n]s", a);
		reverseWords(a);
		printf("%s\n", a);
	}
	return 0;
}
