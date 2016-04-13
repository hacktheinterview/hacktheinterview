
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int A; cin >> A;
		Solution solution;
		vector<vector<int> > result = solution.generateMatrix(A);
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
