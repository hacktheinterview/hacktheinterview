#include <stdio.h>
#include <stdlib.h>

int search(const int* A, int N, int key) {
    int L = 0;
    int R = N - 1;

    while (L <= R) {
        // Avoid overflow, same as M=(L+R)/2
        int M = L + ((R - L) / 2);
        if (A[M] == key) return M;

    // the bottom half is sorted
        if (A[L] <= A[M]) {
            if (A[L] <= key && key < A[M])
                R = M - 1;
            else
                L = M + 1;
        }
    // the upper half is sorted

        else {
            if (A[M] < key && key <= A[R])
                L = M + 1;
            else
                R = M - 1;
        }
    }
    return -1;
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
        int result = search(input, n, K);
		printf("%d\n", result);
	}
	return 0;
}
