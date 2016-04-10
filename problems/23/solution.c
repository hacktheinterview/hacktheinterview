#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMissingUtil(const int* arr, int low, int high, int diff) {
    if (high <= low)
        return INT_MAX;

    int mid = low + (high - low)/2;

    if (arr[mid+1] - arr[mid] != diff)
        return (arr[mid] + diff);

    if (mid > 0 && arr[mid] - arr[mid-1] != diff)
        return (arr[mid-1] + diff);

    if (arr[mid] == arr[0] + mid*diff)
        return findMissingUtil(arr, mid+1, high, diff);

    return findMissingUtil(arr, low, mid-1, diff);
}

int findMissing(const int* A, int N) {
    int diff = (A[N-1] - A[0])/N;
    return findMissingUtil(A, 0, N - 1, diff);
}

int main() {
	setbuf(stdout, NULL);
	int testcases;
	scanf("%d", &testcases);
	int t = 0;
	for (t = 0; t < testcases; t++) {
		int n; scanf("%d", &n);
        int input[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &input[i]);
        }
        int result = findMissing(input, n);
		printf("%d\n", result);
	}
	return 0;
}
