
class Solution {
	// DO NOT MODFIY THE LIST. 
	public int maxSubArray(final List<Integer> a) {
		if (a.size() == 0) {
			return 0;
		}
		int maxSoFar = a.get(0), currentMax = a.get(0);
		for (int i = 1; i < a.size(); i++) {
			currentMax = Math.max(a.get(i), currentMax + a.get(i));
			maxSoFar = Math.max(maxSoFar, currentMax);
		}
		return maxSoFar;
	}
}

