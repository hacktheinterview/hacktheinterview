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
		bool isPower(int a);
};

//--SPLIT--
//-bool Solution::isPower(int A) {
//-}

//--SPLIT--
bool Solution::isPower(int a) {
if (a == 1) {
       return true;
    }
    for (int x = 2; x <= sqrt(a); x++) {
        for (int y = 2; pow(x, y) <= a; y++) {
            if (pow(x, y) == a)
                return true;
        }
    }
    return false;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		bool result = s.isPower(a);
		cout << (result ? "1" : "0") << "\n";
	}
	return 0;
}
