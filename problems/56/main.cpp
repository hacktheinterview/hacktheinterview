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
		unsigned int reverseBits(unsigned int n);
};

unsigned int Solution::reverseBits(unsigned int num) {
	unsigned int cnt = sizeof(num) * 8 - 1;
	unsigned int reverse_num = num;

	num >>= 1;
	while(num) {
		reverse_num <<= 1;
		reverse_num |= num & 1;
		num >>= 1;
		cnt--;
	}
	reverse_num <<= cnt;
	return reverse_num;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		unsigned int n; cin >> n;
        unsigned int result = s.reverseBits(n);
        cout << result << endl;
	}
	return 0;
}
