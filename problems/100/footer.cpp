
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<int> X(n), Y(n);
		for (int i = 0; i < n; i++) {
			cin >> X[i];
		}
		for (int i = 0; i < n; i++) {
        	cin >> Y[i];
        }
		Solution solution;
		cout << solution.coverPoints(X, Y) << "\n";
	}
	return 0;
}
