
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<vector<int> > A(n, std::vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> A[i][j];
			}
		}
		Solution solution;
		vector<vector<int> > result = solution.diagonal(A);
		for (int j = 0; j < result.size(); j++) {
			vector<int> v = result[j];
			for (int k = 0; k < v.size(); k++) {
				cout << v[k]  << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
