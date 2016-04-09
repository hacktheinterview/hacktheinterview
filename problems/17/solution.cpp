
int Solution::binarySearch(const vector<int>& A, int K) {
    int N = (int)A.size();
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
