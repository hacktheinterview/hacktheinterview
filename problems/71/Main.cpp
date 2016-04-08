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
		int titleToNumber(string a);
};

//--SPLIT--
//-int Solution::titleToNumber(string a) {
//-}

//--SPLIT--
int Solution::titleToNumber(string a) {
    int result = 0;
    for (int i = 0; i < a.length(); i++) {
        char c = a.at(a.length() - i - 1);
        result += ((int)c - 'A' + 1) * pow(26, i);
    }
    return result;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		string a; cin >> a;
		cout << s.titleToNumber(a) << "\n";
	}
	return 0;
}
