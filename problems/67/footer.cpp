

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a, b; cin >> a >> b;
		cout << s.gcd(a, b) << "\n";
	}
	return 0;
}
