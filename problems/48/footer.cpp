int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		unsigned int n; cin >> n;
        int result = s.countBits(n);
        cout << result << endl;
	}
	return 0;
}
