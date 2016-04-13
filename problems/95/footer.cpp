
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		Solution solution;
		vector<int> result = solution.maxset(A);
		for (int i = 0; i < result.size() ;i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
