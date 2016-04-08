
class Solution {
	public String convertToTitle(int a) {
		String result = "";
		while (a > 0) {
			int r = (a - 1) % 26;
			result = (char) ('A' + r) + result;
			a = (a - 1) / 26;
		}
		return result;
	}
}


