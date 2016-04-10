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
		int coverPoints(vector<int> &X, vector<int> &Y);
};

//--SPLIT--
//-int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
//-}

//--SPLIT--
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
	return 0;
}

//--SPLIT--
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<int> X(n), Y(n);
		for (int i = 0; i < n; i++) {
			cin >> X[i];
		}
		for (int i = 0; i < n; i++) {
        	cin >> Y[i];
        }
		Solution solution;
		cout << solution.coverPoints(X, Y) << "\n";
	}
	return 0;
}
