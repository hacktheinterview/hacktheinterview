
vector<vector<int> > Solution::generate(int A) {
	vector<vector<int> > result(A);
	for (int i = 0; i < A; i++) {
		vector<int> v(i + 1); 
		v[0] = 1;
		for (int r = 1; r <= i; r++) {
			int next = (v[r - 1] * (i  + 1 - r)) / r;
			v[r] = next;
		}
		result[i] = v;
	}
	return result;
}

