int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int rows, cols;
		scanf("%d %d", &rows, &cols);

        vector<vector<int> >matrix;
		for (int i = 0; i < rows; i++) {
			vector<int> tmp(cols);
			for (int j = 0; j < cols; j++) {
				scanf("%d", &tmp[j]);
			}
			matrix.push_back(tmp);
		}

		int K; scanf("%d", &K);
        int result = s.searchMatrix(matrix, K);
        cout << result << endl;
	}
	return 0;
}
