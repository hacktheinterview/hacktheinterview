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

using namespace std;

class Solution {
	public:
		int rangeBitwiseAnd(int m, int n);
};

int Solution::rangeBitwiseAnd(int m, int n) {
	int k = 0;
	while (1) {
		if (n > m) {
	   		k = k + 1;
		} else {
			return m << k;
		}
		m = m >> 1;
		n = n >> 1;
	}
	return m;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int a, b;
		cin >> a >> b;
        int result = s.rangeBitwiseAnd(a, b);
        cout << result << endl;
	}
	return 0;
}
