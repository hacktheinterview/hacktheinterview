#include <stdio.h>
#include <stdlib.h>

int Floor(const int *A,int N,int x)
{
    int low = 0, high = N-1;
    if (A[high] <= x) {
        return high;
    }

    if(A[low] > x) {
        return -1;
    }

    while(high >= low) {
        int mid = (low+high)/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid] <= x)
        {
            if(mid+1 <= high && A[mid+1] > x)
                return mid;
            else
                low = mid + 1;
        }
        else
        {
            if(mid-1 >= low && A[mid-1] <= x)
                return mid-1;
            else
                high = mid-1;
        }
    }
    return -1;
}

int floorSearch(const int* A, int N, int K) {
    int low = 0, high = N - 1;
    int index = Floor(A, N, K);
    if (index == -1) {
        return -1;
    } else {
        return A[index];
    }
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
        int result = floorSearch(input, n, K);
		printf("%d\n", result);
	}
	return 0;
}
