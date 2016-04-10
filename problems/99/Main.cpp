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
		int maxSubArray(const vector<int> &A);
};

//--SPLIT--
//-int Solution::maxSubArray(const vector<int> &A) {
//-}

//--SPLIT--
int Solution::maxSubArray(const vector<int> &A) {
	return 0;
}

//--SPLIT--
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		Solution solution;
		cout << solution.maxSubArray(A) << "\n";
	}
	return 0;
}
