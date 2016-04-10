

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution solution;
		cout << solution.longestCommonPrefix(a) << "\n";
	}
	return 0;
}
