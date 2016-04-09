
int Solution::reverse(int a) {
	int sign = a >= 0 ? 1 : -1;
	a = abs(a);
	long rev_num = 0;
    while(a > 0)
    {
        rev_num = rev_num*10 + a%10;
        a = a/10;
    }
    if (rev_num > INT_MAX) {
        return 0;
    }
	return rev_num * sign;
}

