vector<int> Solution::kLargestElements(const vector<int>& input, int K) {
    priority_queue <int, vector<int>, greater<int>> Q;
    int i = 0;
    for (i = 0; i < (int)input.size(); i++) {
        if (Q.size() < K) {
            Q.push(input[i]);
        } else if (Q.top() < input[i]) {
            Q.pop();
            Q.push(input[i]);
        }
    }
    vector<int> ret;
    while (!Q.empty()) {
        ret.push_back(Q.top());
        Q.pop();
    }
    return ret;
}
