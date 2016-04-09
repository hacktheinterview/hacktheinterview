import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public int trailingZeroes(int a) {
//-	}
//-}


//--SPLIT--
class Solution {
	public int trailingZeroes(int a) {
		int result = 0;
		while (a > 0) {
			result += a/5;
			a /= 5;
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
			int a = Integer.parseInt(reader.readLine());
			System.out.println(s.trailingZeroes(a));
		}
	}
}
