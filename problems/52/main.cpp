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
		int singleNumber(const vector<int>& input);
};

int Solution::singleNumber(const vector<int>& input) {
    // Implement the solution
	int ret = 0;
	for (const auto& element: input) {
		ret = ret ^ element;
	}
	return ret;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
        Solution s;
		int n; cin >> n;
        vector<int> input(n, 0);
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            input[j] = x;
        }
        int result = s.singleNumber(input);
        cout << result << endl;
	}
	return 0;
}
