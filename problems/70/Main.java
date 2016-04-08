import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public String convertToTitle(int a) {
//-	}
//-}

//--SPLIT--
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


//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution s = new Solution();
		for (int i = 1; i <= cases; i++) {
			int input = Integer.parseInt(reader.readLine());
			System.out.println(s.convertToTitle(input));
		}
	}
}
