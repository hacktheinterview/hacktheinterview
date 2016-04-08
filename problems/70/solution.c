
char* convertToTitle(int a) {
	char *result = (char *)malloc(100 * sizeof(char));
	while (a > 0) {
        int r = (a - 1) % 26;
         result = (char) ('A' + r) + result;
        a = (a - 1) / 26;
    }
	return result;
}


