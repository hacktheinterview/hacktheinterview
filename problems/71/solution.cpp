
int Solution::titleToNumber(string a) {
    int result = 0;
    for (int i = 0; i < a.length(); i++) {
        char c = a.at(a.length() - i - 1);
        result += ((int)c - 'A' + 1) * pow(26, i);
    }
    return result;
}

