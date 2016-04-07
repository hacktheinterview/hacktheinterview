
vector<int> Solution::primesum(int a) {
	vector<int> result;
	bool *isPrime = new bool[a + 1];
    for (int i = 2; i <= a; i++) {
        isPrime[i] = true;
    }
    for(int i = 2; i <=a; i++) {
        for (int j = 2; i * j <= a; j++) {
            isPrime[i * j] = false;
        }
    }

	for (int i = 2; i < a; i++) {
        int j = a - i;
        if (isPrime[i] && isPrime[j]) {
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
	return result;
}

