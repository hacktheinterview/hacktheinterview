import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-public class Solution {
//-	public int reverse(int a) {
//-	}
//-}


//--SPLIT--
class Solution {
	public int reverse(int a) {
		return a;
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
			System.out.println(s.reverse(input));
		}
	}
}
