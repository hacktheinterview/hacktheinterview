

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		vector<int> result = s.primesum(a);
		cout << "[" << result.at(0) << ", " << result.at(1) << "]" << "\n";
	}
	return 0;
}
