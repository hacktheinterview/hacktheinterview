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
		int trailingZeroes(int a);
};

//--SPLIT--
//-int Solution::trailingZeroes(int a) {
//-}

//--SPLIT--
int Solution::trailingZeroes(int a) {
	int result = 0;
	while (a > 0) {
		result += a/5;
		a /= 5;
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
		cout << s.trailingZeroes(a) << "\n";
	}
	return 0;
}
