

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		string a; cin >> a;
		Solution solution;
		cout << solution.lengthOfLastWord(a) << "\n";
	}
	return 0;
}
