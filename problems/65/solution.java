
class Solution {
	public int findRank(String s) {
		if (s.length() == 1) {
			return 1;
		}
		char[] chars = s.toCharArray();
		Arrays.sort(chars);
		String sorted = new String(chars);
		int pos = sorted.indexOf(s.charAt(0));
		int result = pos;
		for (int i = s.length() - 1; i > 0; i--) {
			result = (result * i) % 1000003;
		}
		return (result + findRank(s.substring(1))) % 1000003;
	}
}



