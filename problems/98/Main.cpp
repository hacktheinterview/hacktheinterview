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
		vector<int> plusOne(vector<int> &A);
};

//--SPLIT--

//-vector<int> Solution::plusOne(vector<int> &A) {
//-}

//--SPLIT--
vector<int> Solution::plusOne(vector<int> &A) {
	return A;
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
		vector<int> result = solution.plusOne(A);
		for (int i = 0; i < result.size() ;i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
