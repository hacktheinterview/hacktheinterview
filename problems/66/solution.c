
int trailingZeroes(int a) {
	int result = 0;
    while (a > 0) {
        result += a/5;
        a /= 5;
    }
    return result;
}


