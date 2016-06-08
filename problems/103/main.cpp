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
		vector<int> topKFrequent(const vector<int>& input, int K);
};

vector<int> Solution::topKFrequent(const vector<int>& input, int K) {
    map<int, int> M;
    for (const auto& element: input)
        M[element]++;


    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
    for (const auto& x: M) {
        if (Q.size() < K)
            Q.push({x.second, x.first});
        else if (Q.top().first < x.second) {
            Q.pop();
            Q.push({x.second, x.first});
        }
    }

    vector<int> ret;
    while (!Q.empty()) {
        ret.push_back(Q.top().second);
        Q.pop();
    }
    return ret;
}

void printVector(const vector<int>& result) {
    if (result.size() == 0) {
        cout << endl;
        return;
    }

    for (int i = 0; i < (int)result.size() - 1; i++)
        cout << result[i] << " ";
    cout << result[(int)result.size() - 1] << endl;
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
        int K; cin >> K;
        auto result = s.topKFrequent(input, K);
        printVector(result);
	}
	return 0;
}
