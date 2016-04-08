
int titleToNumber(char* a) {
	int result = 0;
    for (int i = 0; i < strlen(a); i++) {
        char c = a[strlen(a) - i - 1];
        result += ((int)c - 'A' + 1) * pow(26, i);
    }
    return result;
}


