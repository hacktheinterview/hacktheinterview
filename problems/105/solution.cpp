int Solution::minCost(const vector<int>& input) {
    priority_queue <int, vector<int>, greater<int>> pq;
    for (const auto& x: input)
        pq.push(x);

    int res = 0;

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        // Connect the ropes: update result and
        // insert the new rope to pq
        res += first + second;
        pq.push(first + second);
    }
    return res;
}
