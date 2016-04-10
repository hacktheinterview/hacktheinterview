int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int n; cin >> n;
        int result = s.squareRoot(n);
        cout << result << endl;
	}
	return 0;
}
