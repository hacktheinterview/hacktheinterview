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
		bool isPalindrome(int a);
};

//--SPLIT--
//-bool Solution::isPalindrome(int a) {
//-}

//--SPLIT--
bool Solution::isPalindrome(int a) {
	int rev_num = 0, num = a;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
	return rev_num == a;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		cout << (s.isPalindrome(a) ? "1" : "0") << "\n";
	}
	return 0;
}
