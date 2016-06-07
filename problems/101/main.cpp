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
		int isPalindrome(unsigned int n);
};

bool isKthBitSet(unsigned int x, unsigned int k) {
	return (x & (1 << (k-1)))? true: false;
}

int Solution::isPalindrome(unsigned int n) {
	int l = 1; // Initialize left position
	int r = sizeof(unsigned int) * 8; // initialize right position

	// One by one compare bits
	while (l < r) {
		if (isKthBitSet(n, l) != isKthBitSet(n, r))
			return 0;
		l++;
		r--;
	}
	return 1;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		unsigned int n; cin >> n;
        int result = s.isPalindrome(n);
        cout << result << endl;
	}
	return 0;
}
