import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-public class Solution {
//-	public boolean isPalindrome(int a) {
//-	}
//-}


//--SPLIT--
class Solution {
	public boolean isPalindrome(int a) {
		StringBuilder value = new StringBuilder();
		value.append(String.valueOf(a));
		return String.valueOf(a).equals(value.reverse().toString());
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
			System.out.println(s.isPalindrome(input) ? "1" : "0");
		}
	}
}
