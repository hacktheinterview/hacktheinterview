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
		void arrange(vector<int> &a);
};

//--SPLIT--
//-void Solution::arrange(vector<int> &a) {
//-}

//--SPLIT--
void Solution::arrange(vector<int> &a) {
	
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		s.arrange(a);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
