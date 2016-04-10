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
		int lengthOfLastWord(const string &a);
};

//--SPLIT--
//-int Solution::lengthOfLastWord(const string &a) {
//-}

//--SPLIT--
int Solution::lengthOfLastWord(const string &a) {
	return 0;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		string a; cin >> a;
		Solution solution;
		cout << solution.lengthOfLastWord(a) << "\n";
	}
	return 0;
}
