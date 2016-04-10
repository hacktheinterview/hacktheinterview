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

int getRequiredPainters(const vector<int>& input, int costPerUnit, int maxLengthPerPainter) {
  int total = 0, numPainters = 1;
  for (int i = 0; i < input.size(); i++) {
    total += costPerUnit * input[i];
    if (total > maxLengthPerPainter) {
      total = input[i];
      numPainters++;
    }
  }
  return numPainters;
}

// A is number of painters
// B is cost of painting per unit
int Solution::paintBoards(int numPainters, int costPerUnit,
						const vector<int>& boardLengths) {
	int lo = getMax(boardLengths) * costPerUnit;
    int hi = getSum(boardLengths) * costPerUnit;

    while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		int requiredPainters = getRequiredPainters(boardLengths, costPerUnit, mid);
		if (requiredPainters <= numPainters) {
			hi = mid;
		} else {
			lo = mid+1;
		}
    }
    return lo;
}
