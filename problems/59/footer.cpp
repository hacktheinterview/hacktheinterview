

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		Solution solution;
		cout << solution.countAndSay(a) << "\n";
	}
	return 0;
}
