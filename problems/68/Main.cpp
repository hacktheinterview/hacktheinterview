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
		int reverse(int a);
};

//--SPLIT--
//-int Solution::reverse(int a) {
//-}

//--SPLIT--
int Solution::reverse(int a) {
	int sign = a >= 0 ? 1 : -1;
	a = abs(a);
	long rev_num = 0;
    while(a > 0)
    {
        rev_num = rev_num*10 + a%10;
        a = a/10;
    }
    if (rev_num > INT_MAX) {
        return 0;
    }
	return rev_num * sign;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		cout << s.reverse(a) << "\n";
	}
	return 0;
}
