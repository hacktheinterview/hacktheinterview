import java.io.*;
import java.util.*;

//--SPLIT--

//-class Solution {
//-	public ArrayList<ArrayList<Integer>> generate(int a) {
//-	}
//-}

//--SPLIT--
class Solution {
	public ArrayList<ArrayList<Integer>> generate(int a) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < a; i++) {
			ArrayList<Integer> arrayList = new ArrayList<Integer>();
			arrayList.add(1);
			for (int r = 1; r <= i; r++) {
				int next = (arrayList.get(r - 1) * (i  + 1 - r)) / r;
				arrayList.add(next);
			}
			result.add(arrayList);
		}
		return result;
	}
}

//--SPLIT--
public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			int a = Integer.parseInt(reader.readLine());
			Solution solution = new Solution();
			ArrayList<ArrayList<Integer>> result = solution.generate(a);
			for (int j = 0; j < result.size(); j++) {
				ArrayList<Integer> arrayList = result.get(j);
				for (int k = 0; k < arrayList.size(); k++) {
					System.out.print(arrayList.get(k) + " ");
				}
				System.out.println();
			}
		}
	}
}
