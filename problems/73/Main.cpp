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

using namespace std;

class Solution {
	public:
		vector<int> primesum(int a);
};

//--SPLIT--

//vector<int> Solution::primesum(int a) {
//}

//--SPLIT--
vector<int> Solution::primesum(int a) {
	vector<int> result;
	bool *isPrime = new bool[a];
    for (int i = 2; i <= a; i++) {
        isPrime[i] = true;
    }
    for(int i = 2; i <=a; i++) {
        for (int j = 2; i * j <= a; j++) {
            isPrime[i * j] = false;
        }
    }

	for (int i = 2; i < a; i++) {
        int j = a - i;
        if (isPrime[i] && isPrime[j]) {
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
	return result;
}

//--SPLIT--

int main() {
	int testcases;
	cin >> testcases;
    Solution s;
	for (int t = 0; t < testcases; t++) {
		int a; cin >> a;
		vector<int> result = s.primesum(a);
		cout << "[" << result.at(0) << ", " << result.at(1) << "]" << "\n";
	}
	return 0;
}
