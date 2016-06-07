void printVector(const vector<int>& result) {
    if (result.size() == 0) {
        cout << endl;
        return;
    }

    for (int i = 0; i < (int)result.size() - 1; i++)
        cout << result[i] << " ";
    cout << result[(int)result.size() - 1] << endl;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int n; cin >> n;
        vector<int> input(n);
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            input[j] = x;
        }
        int K; cin >> K;
        auto result = s.topKFrequent(input, K);
        printVector(result);
	}
	return 0;
}
