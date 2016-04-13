
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int A; cin >> A;
		Solution solution;
		vector<int> result = solution.getRow(A);
		for (int i = 0; i < result.size() ;i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
