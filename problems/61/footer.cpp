

int main() {
	int testcases;
	cin >> testcases;
    Solution solution;
	for (int t = 0; t < testcases; t++) {
		string s;
		cin >> s;
		cout << solution.isPalindrome(s) << "\n";
	}
	return 0;
}
