int Solution::singleNumber(const vector<int>& input) {
    // Implement the solution
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;

	for (int i = 0; i < n; i++) {
		t1 = t1 ^ A[i];
		t2 = t2 | ((t1^A[i]) & A[i]);
		t3 = ~(t1 & t2);
		t1 = t1 & t3;
		t2 = t2 & t3;
	}
	
	return t1;
}
