import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public int gcd(int a, int b) {
//-	}
//-}


//--SPLIT--
class Solution {
	public int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}
}



//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution s = new Solution();
		for (int i = 1; i <= cases; i++) {
			String inputLine = reader.readLine();
			String inputItems[] = inputLine.split(" ");
			int a = Integer.parseInt(inputItems[0]);
			int b = Integer.parseInt(inputItems[1]);
			System.out.println(s.gcd(a, b));
		}
	}
}
