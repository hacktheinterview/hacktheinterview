
class Solution {
	public ArrayList<ArrayList<Integer>> generate(int a) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < a; i++) {
			ArrayList<Integer> arrayList = new ArrayList<Integer>();
			arrayList.add(1);
			for (int r = 1; r <= i; r++) {
				int next = (arrayList.get(r - 1) * (i  + 1 - r)) / r;
				arrayList.add(next);
			}
			result.add(arrayList);
		}
		return result;
	}
}

