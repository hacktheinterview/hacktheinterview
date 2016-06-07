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
		int countBits(unsigned int n);
};

int Solution::countBits(unsigned int n) {
    int ans = 0;
    while (n > 0) {
        ans++;
        n = (n) & (n - 1);
    }
    return ans;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		unsigned int n; cin >> n;
        int result = s.countBits(n);
        cout << result << endl;
	}
	return 0;
}
