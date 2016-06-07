int Solution::sumHammingDistance(const vector<int>& input) {
    // Implement the solution
	int ret = 0;
	for (int i = 0; i < 31; i++) {
		int zeros = 0, ones = 0;
		for (int j = 0; j < input.size(); j++) {
			if ((input[j] & (1<<i)))
				ones++;
			else
				zeros++;
		}
		ret += ones * zeros;
	}
	return ret;
}
