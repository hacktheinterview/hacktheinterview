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
		int search(const vector<int>& input, int K);
};

int Solution::search(const vector<int>& A, int K) {
    vector<int>::const_iterator low = std::lower_bound(A.begin(), A.end(), K);
    if (low == A.end()) {
        return -1;
    }
    return *low;
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
        int k; cin>> k;
        int result = s.search(input, k);
        cout << result << endl;
	}
	return 0;
}
