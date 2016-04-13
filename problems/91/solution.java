
class Solution {
	public ArrayList<ArrayList<Integer>> diagonal(ArrayList<ArrayList<Integer>> a) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < 2 * a.size() - 1; i++) {
			result.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < a.size(); i++) {
			int x = 0, y = i;
			ArrayList<Integer> r = result.get(x + y);
			while (x < a.size() && y >= 0) {
				r.add(a.get(x).get(y));
				x = x + 1;
				y = y - 1;
			}
		}
		for (int i = 1; i < a.size(); i++) {
			int x = i, y = a.size() - 1;
			ArrayList<Integer> r = result.get(x + y);
			while (x < a.size() && y >= 0) {
				r.add(a.get(x).get(y));
				x = x + 1; y = y - 1;
			}
		}
		return result;
	}
}
	