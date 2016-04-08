
class Solution {
	public boolean isPalindrome(int a) {
		StringBuilder value = new StringBuilder();
		value.append(String.valueOf(a));
		return String.valueOf(a).equals(value.reverse().toString());
	}
}



