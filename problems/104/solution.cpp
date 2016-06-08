vector<int> Solution::sortNearlySortedArray(const vector<int>& input, int K) {
    vector<int> ret = input;
    sort(ret.begin(), ret.end());
    return ret;
}
