

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		bool result = s.isPower(a);
		cout << (result ? "1" : "0") << "\n";
	}
	return 0;
}
