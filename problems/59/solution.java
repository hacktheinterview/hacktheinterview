
class Solution {
	public String countAndSay(int a) {
		if (a == 1) {
			return "1";
		}
		String sub = countAndSay(a - 1);
		String result = "";
		int i = 1, count = 1;
		char ch = sub.charAt(0);
		for (; i < sub.length(); i++) {
			if (ch == sub.charAt(i)) {
				count++; continue;
			}
			result = result + count + "" + ch;
			ch = sub.charAt(i);
			count = 1;
		}
		result = result + count + "" + ch;
		return result;
	}
}


