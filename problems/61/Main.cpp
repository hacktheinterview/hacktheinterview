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
		int isPalindrome(string a);
};

//--SPLIT--
//-int Solution::isPalindrome(string a) {
//-}

//--SPLIT--
int Solution::isPalindrome(string a) {
	return 0;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution solution;
	for (int t = 0; t < testcases; t++) {
		string s;
		cin >> s;
		cout << solution.isPalindrome(s) << "\n";
	}
	return 0;
}
