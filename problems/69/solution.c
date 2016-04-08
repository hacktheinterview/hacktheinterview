
int isPalindrome(int a) {
	int rev_num = 0, num = a;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num == a ? 1 : 0;
}


