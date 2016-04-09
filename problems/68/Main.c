#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//--SPLIT--

/**
 * @input A : Integer
 *
 * @Output Integer 0 / 1. Return 0 if the number is not palindrome, else return 1
 */
//-int isPalindrome(int a) {
//-}


//--SPLIT--
int isPalindrome(int a) {
	int rev_num = 0, num = a;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num == a ? 1 : 0;
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
		printf("%d\n", isPalindrome(a));
	}
	return 0;
}
