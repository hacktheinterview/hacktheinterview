import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public String longestCommonPrefix(ArrayList<String> a) {
//-	}
//-}


//--SPLIT--
class Solution {
	public String longestCommonPrefix(ArrayList<String> a) {
		return "";
	}
}



//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			String[] inputLines = reader.readLine().split(" ");
			int n = Integer.parseInt(inputLines[0]);
			ArrayList<String> a = new ArrayList<String>();
			for (int j = 1; j < n; j++) {
				a.add(inputLines[j]);
			}
			Solution solution = new Solution();
			System.out.println(solution.longestCommonPrefix(a));
		}
	}
}
