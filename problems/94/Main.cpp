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
		vector<int> getRow(int A);
};

//--SPLIT--

//-vector<int> Solution::getRow(int A) {
//-}

//--SPLIT--
vector<int> Solution::getRow(int A) {
	vector<int> result(A + 1);
	return result;
}

//--SPLIT--
int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int A; cin >> A;
		Solution solution;
		vector<int> result = solution.getRow(A);
		for (int i = 0; i < result.size() ;i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
