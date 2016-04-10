int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int n; cin >> n;
        vector<int> input(n);
        for (int j = 0; j < n; j++) {
            int x; scanf("%d", &input[j]);
        }
		int numPainters, costPerUnit;
		cin >> numPainters >> costPerUnit;
        int result = s.paintBoards(numPainters, costPerUnit, input);
        cout << result << endl;
	}
	return 0;
}
