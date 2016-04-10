
class Solution {
	// DO NOT MODIFY THE LIST
	public ArrayList<Integer> repeatedNumber(final List<Integer> a) {
		int n = a.size();
		int s = (n * (n + 1)) / 2;
		int ss = (n * (n + 1) * (2 * n + 1)) / 6;
		int sa = 0, ssa = 0;
		for (int i = 0; i < n; i++) {
			sa += a.get(i);
			ssa += a.get(i) * a.get(i);
		}
		int diff = sa - s;
		int sum = (ssa - ss) / diff;
		ArrayList<Integer> result = new ArrayList<Integer>();
		result.add((sum + diff) / 2);
		result.add((sum - diff) / 2);
		return result;
	}
}

