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
		string convertToTitle(int a);
};

//--SPLIT--
//-string Solution::convertToTitle(int A) {
//-}

//--SPLIT--
string Solution::convertToTitle(int a) {
	string result = "";
	while (a > 0) {
		int r = (a - 1) % 26;
		result = (char) ('A' + r) + result;
		a = (a - 1) / 26;
	}
	return result;
}
//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		cout << s.convertToTitle(a) << "\n";
	}
	return 0;
}
