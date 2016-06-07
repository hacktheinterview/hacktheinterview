int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int a, b;
		cin >> a >> b;
        auto result = s.divide(a, b);
        cout << result << endl;
	}
	return 0;
}
