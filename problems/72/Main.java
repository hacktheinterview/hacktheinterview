import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-public class Solution {
//-	public boolean isPower(int a) {
//-	}
//-}

//--SPLIT--
class Solution {
	public boolean isPower(int a) {
		if (a == 1) {
			return true;
		}
		for (int x = 2; x <= Math.sqrt(a); x++) {
			for (int y = 2; Math.pow(x, y) <= a; y++) {
				if (Math.pow(x, y) == a)
					return true;
			}
		}
		return false;
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
			int a = Integer.parseInt(input);
			System.out.println(s.isPower(a) ? "1" : "0");
		}
	}
}
