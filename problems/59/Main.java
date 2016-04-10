import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public String countAndSay(int a) {
//-	}
//-}



//--SPLIT--
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


//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			int a = Integer.parseInt(reader.readLine());
			Solution solution = new Solution();
			System.out.println(solution.countAndSay(a));
		}
	}
}
