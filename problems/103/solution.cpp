vector<int> Solution::topKFrequent(const vector<int>& input, int K) {
    map<int, int> M;
    for (const auto& element: input)
        M[element]++;


    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
    for (const auto& x: M) {
        if (Q.size() < K)
            Q.push({x.second, x.first});
        else if (Q.top().first < x.second) {
            Q.pop();
            Q.push({x.second, x.first});
        }
    }

    vector<int> ret;
    while (!Q.empty()) {
        ret.push_back(Q.top());
        Q.pop();
    }
    return ret;
}
