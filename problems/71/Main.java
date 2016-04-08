import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-public class Solution {
//-	public int titleToNumber(String a) {
//-	}
//-}

//--SPLIT--
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

//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution s = new Solution();
		for (int i = 1; i <= cases; i++) {
			String input = reader.readLine();
			System.out.println(s.titleToNumber(input));
		}
	}
}
