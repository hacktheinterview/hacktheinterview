#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int squareRoot(int N) {
    if (N == 0) {
        return 0;
    }
    int lo = 1, hi = N;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (mid <= N / mid) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n; scanf("%d", &n);
        int result = squareRoot(n);
        printf("%d\n", result);
	}
	return 0;
}
