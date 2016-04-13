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
		vector<vector<int> > generate(int A);
};

//--SPLIT--

//-vector<vector<int> > Solution::generate(int A) {
//-}

//--SPLIT--
vector<vector<int> > Solution::generate(int A) {
	vector<vector<int> > result(A);
	for (int i = 0; i < A; i++) {
		vector<int> v(i + 1); 
		v[0] = 1;
		for (int r = 1; r <= i; r++) {
			int next = (v[r - 1] * (i  + 1 - r)) / r;
			v[r] = next;
		}
		result[i] = v;
	}
	return result;
}

//--SPLIT--
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int A; cin >> A;
		Solution solution;
		vector<vector<int> > result = solution.generate(A);
		for (int j = 0; j < result.size(); j++) {
			vector<int> v = result[j];
			for (int k = 0; k < v.size(); k++) {
				cout << v[k]  << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
