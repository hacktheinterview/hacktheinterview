int Solution::searchMatrix(const vector<vector<int>>& matrix, int target) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == target) {
				return 1;
			}
		}
	}
	return 0;
}
