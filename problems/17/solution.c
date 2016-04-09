
int binarySearch(const int* A, int N, int K) {
    // Implement the solution
    int low = 0, high = N - 1, mid;
    while(low <= high) {
        mid = (low + high)/2;
        if(A[mid] < K) {
                low = mid + 1;
        } else if(A[mid] == K) {
                return mid;
        } else if(A[mid] > K) {
                high = mid-1;
        }
    }
    return -1;
}
