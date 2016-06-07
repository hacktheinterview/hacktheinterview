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
#include <climits>

using namespace std;

class Solution {
	public:
		int sumHammingDistance(const vector<int>& input);
};

int Solution::sumHammingDistance(const vector<int>& input) {
    // Implement the solution
	int ret = 0;
	for (int i = 0; i < 31; i++) {
		int zeros = 0, ones = 0;
		for (int j = 0; j < input.size(); j++) {
			if ((input[j] & (1<<i)))
				ones++;
			else
				zeros++;
		}
		ret += ones * zeros;
	}
	return ret;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int n; cin >> n;
        vector<int> input(n);
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            input[j] = x;
        }
        int result = s.sumHammingDistance(input);
        cout << result << endl;
	}
	return 0;
}
