import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	// DO NOT MODIFY THE LIST
//-	public ArrayList<Integer> repeatedNumber(final List<Integer> a) {
//-	}
//-}

//--SPLIT--
class Solution {
	// DO NOT MODIFY THE LIST
	public ArrayList<Integer> repeatedNumber(final List<Integer> a) {
		int n = a.size();
		int s = (n * (n + 1)) / 2;
		int ss = (n * (n + 1) * (2 * n + 1)) / 6;
		int sa = 0, ssa = 0;
		for (int i = 0; i < n; i++) {
			sa += a.get(i);
			ssa += a.get(i) * a.get(i);
		}
		int diff = sa - s;
		int sum = (ssa - ss) / diff;
		ArrayList<Integer> result = new ArrayList<Integer>();
		result.add((sum + diff) / 2);
		result.add((sum - diff) / 2);
		return result;
	}
}

//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			Solution solution = new Solution();
			String[] input = reader.readLine().split(" ");
			int n = Integer.parseInt(input[0]);
			ArrayList<Integer> a = new ArrayList<Integer>();
			for (int j = 1; j <= n; j++) {
				a.add(Integer.parseInt(input[j]));
			}
			ArrayList<Integer> result = solution.repeatedNumber(a); 
			System.out.println(result.get(0) + " " + result.get(1));
		}
	}
}
