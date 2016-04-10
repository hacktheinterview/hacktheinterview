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
		string countAndSay(int a);
};

//--SPLIT--
//-string Solution::countAndSay(int a) {
//-}

//--SPLIT--
string Solution::countAndSay(int a) {
	return "";
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		Solution solution;
		cout << solution.countAndSay(a) << "\n";
	}
	return 0;
}
