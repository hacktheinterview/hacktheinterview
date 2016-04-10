
class Solution {
	// X and Y co-ordinates of the points in order.
	// Each point is represented by (X.get(i), Y.get(i))
	public int coverPoints(ArrayList<Integer> X, ArrayList<Integer> Y) {
		int result = 0;
		for (int i = 1; i < X.size(); i++) {
			int a = Math.abs(X.get(i) - X.get(i - 1));
			int b = Math.abs(Y.get(i) - Y.get(i - 1));
			result += Math.abs(b - a);
			result += (a > b) ? b : a;
		}
		return result;
	}
}




