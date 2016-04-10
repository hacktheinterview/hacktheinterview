import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public int maxSubArray(final List<Integer> a) {
//-	}
//-}

//--SPLIT--
class Solution {
	// DO NOT MODFIY THE LIST. 
	public int maxSubArray(final List<Integer> a) {
		if (a.size() == 0) {
			return 0;
		}
		int maxSoFar = a.get(0), currentMax = a.get(0);
		for (int i = 1; i < a.size(); i++) {
			currentMax = Math.max(a.get(i), currentMax + a.get(i));
			maxSoFar = Math.max(maxSoFar, currentMax);
		}
		return maxSoFar;
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
			System.out.println(solution.maxSubArray(a));
		}
	}
}
