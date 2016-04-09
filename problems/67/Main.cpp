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
		int gcd(int a, int b);
};

//--SPLIT--
//-int Solution::gcd(int a, int b) {
//-}

//--SPLIT--
int Solution::gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b%a, a);
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a, b; cin >> a >> b;
		cout << s.gcd(a, b) << "\n";
	}
	return 0;
}
