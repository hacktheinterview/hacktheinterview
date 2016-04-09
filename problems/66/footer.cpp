

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		cout << s.trailingZeroes(a) << "\n";
	}
	return 0;
}
