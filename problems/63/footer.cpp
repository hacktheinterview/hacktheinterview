

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		s.arrange(a);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
