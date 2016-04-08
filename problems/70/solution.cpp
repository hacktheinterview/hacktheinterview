
string Solution::convertToTitle(int a) {
	string result = "";
	while (a > 0) {
		int r = (a - 1) % 26;
		result = (char) ('A' + r) + result;
		a = (a - 1) / 26;
	}
	return result;
}
