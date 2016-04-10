

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		string a; cin >> a;
		Solution solution;
		solution.reverseWords(a);
		cout << a << "\n";
	}
	return 0;
}
