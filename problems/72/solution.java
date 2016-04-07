
class Solution {
	public boolean isPower(int a) {
		if (a == 1) {
			return true;
		}
		for (int x = 2; x <= Math.sqrt(a); x++) {
			for (int y = 2; Math.pow(x, y) <= a; y++) {
				if (Math.pow(x, y) == a)
					return true;
			}
		}
		return false;
	}
}

