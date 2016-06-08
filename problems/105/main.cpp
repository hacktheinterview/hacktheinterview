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
		int minCost(const vector<int>& input);
};

int Solution::minCost(const vector<int>& input) {
    priority_queue <int, vector<int>, greater<int>> pq;
    for (const auto& x: input)
        pq.push(x);

    int res = 0;

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        // Connect the ropes: update result and
        // insert the new rope to pq
        res += first + second;
        pq.push(first + second);
    }
    return res;
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
        auto result = s.minCost(input);
		cout << result << endl;
	}
	return 0;
}
