

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		string a; cin >> a;
		cout << s.titleToNumber(a) << "\n";
	}
	return 0;
}
