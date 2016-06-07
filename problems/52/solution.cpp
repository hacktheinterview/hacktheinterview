int Solution::singleNumber(const vector<int>& input) {
    // Implement the solution
	int ret = 0;
	for (const auto& element: input)
		ret = ret ^ element;
	return ret;
}
