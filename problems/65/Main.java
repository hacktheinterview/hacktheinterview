import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public int findRank(String s) {
//-	}
//-}


//--SPLIT--
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



//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution solution = new Solution();
		for (int i = 1; i <= cases; i++) {
			String s = reader.readLine();
			System.out.println(solution.findRank(s));
		}
	}
}
