#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <math.h>

using namespace std;

class Solution {
	public:
		string longestCommonPrefix(vector<string> &a);
};

//--SPLIT--
//-string Solution::longestCommonPrefix(vector<string> &a) {
//-}

//--SPLIT--
string Solution::longestCommonPrefix(vector<string> &a) {
	return "";
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution solution;
		cout << solution.longestCommonPrefix(a) << "\n";
	}
	return 0;
}
