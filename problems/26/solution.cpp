int getMax(const vector<int>& input) {
	int max = INT_MIN;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] > max) max = input[i];
	}
	return max;
}

int getSum(const vector<int>& input) {
	int total = 0;
	for (int i = 0; i < input.size(); i++) {
		total += input[i];
	}
	return total;
}

int getRequiredStudents(const vector<int>& input, int maxPagePerStudent) {
  int total = 0, numStudents = 1;
  for (int i = 0; i < input.size(); i++) {
    total += input[i];
    if (total > maxPagePerStudent) {
      total = input[i];
      numStudents++;
    }
  }
  return numStudents;
}

// A is number of painters
// B is cost of painting per unit
int Solution::copyBooks(int numStudents, const vector<int>& bookPages) {
	int lo = getMax(bookPages);
    int hi = getSum(bookPages);

    while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		int requiredStudents = getRequiredStudents(bookPages, mid);
		if (requiredStudents <= numStudents) {
			hi = mid;
		} else {
			lo = mid+1;
		}
    }
    return lo;
}
