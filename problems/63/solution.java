
class Solution {
	public void arrange(ArrayList<Integer> a) {
		int n = a.size();
		for (int i=0; i < a.size(); i++) {
			int newVal = a.get(i) + (a.get(a.get(i)) % n) * n;
			a.set(i, newVal);
		}
		// Second Step: Divide all values by n
		for (int i = 0; i < a.size(); i++)
			a.set(i, a.get(i) / n);
	}
}



