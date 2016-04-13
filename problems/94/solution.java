
class Solution {
	public ArrayList<Integer> getRow(int a) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		result.add(1);
		
		for (int r = 1; r <= a; r++) {
			int next = (result.get(r - 1) * (a  + 1 - r)) / r;
			result.add(next);
		}
		return result;
	}
}


