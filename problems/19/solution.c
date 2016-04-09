#include <stdio.h>
#include <stdlib.h>

int ceilSearchRecursive(const int* arr, int low, int high, int x) {
    int mid;
    if(x <= arr[low]) {
        return low;
    }

    if(x > arr[high]) {
        return -1;
    }

    mid = (low + high)/2;
    if(arr[mid] == x) {
        return mid;
    } else if(arr[mid] < x) {
        if(mid + 1 <= high && x <= arr[mid+1])
            return mid + 1;
        else
            return ceilSearchRecursive(arr, mid+1, high, x);
    } else {
        if(mid - 1 >= low && x > arr[mid-1])
            return mid;
        else
            return ceilSearchRecursive(arr, low, mid - 1, x);
    }
}

int ceilSearch(const int* A, int N, int K) {
    int low = 0, high = N - 1;
    int index = ceilSearchRecursive(A, low, high, K);
    if (index == -1)
        return index;
    else
        return A[index];
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
        int K; scanf("%d", &K);
        int result = ceilSearch(input, n, K);
		printf("%d\n", result);
	}
	return 0;
}
