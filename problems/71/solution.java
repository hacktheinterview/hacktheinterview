
class Solution {
	public int titleToNumber(String a) {
		int result = 0;
		for (int i = 0; i < a.length(); i++) {
			char c = a.charAt(a.length() - i - 1);
			result += (int)c - 'A' + 1) * Math.pow(26, i);
		}
		return result;
	}
}

