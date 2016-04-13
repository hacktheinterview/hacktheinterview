import java.io.*;
import java.util.*;

//--SPLIT--

//-class Solution {
//-	public ArrayList<ArrayList<Integer>> diagonal(ArrayList<ArrayList<Integer>> a) {
//-	}
//-}

//--SPLIT--
class Solution {
	public ArrayList<ArrayList<Integer>> diagonal(ArrayList<ArrayList<Integer>> a) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < 2 * a.size() - 1; i++) {
			result.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < a.size(); i++) {
			int x = 0, y = i;
			ArrayList<Integer> r = result.get(x + y);
			while (x < a.size() && y >= 0) {
				r.add(a.get(x).get(y));
				x = x + 1;
				y = y - 1;
			}
		}
		for (int i = 1; i < a.size(); i++) {
			int x = i, y = a.size() - 1;
			ArrayList<Integer> r = result.get(x + y);
			while (x < a.size() && y >= 0) {
				r.add(a.get(x).get(y));
				x = x + 1; y = y - 1;
			}
		}
		return result;
	}
}
	//--SPLIT--
	public class Main {
		public static void main(String args[]) throws Exception {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			int cases = Integer.parseInt(reader.readLine());
			for (int testCase = 1; testCase <= cases; testCase++) {
				int a = Integer.parseInt(reader.readLine());
				ArrayList<ArrayList<Integer>> input = new ArrayList<ArrayList<Integer>>();
				for (int i = 0; i < a; i++) {
					String[] inputLine = reader.readLine().split(" ");
					ArrayList<Integer> r = new ArrayList<Integer>();
					for (int j = 0; j < inputLine.length; j++) {
						r.add(Integer.parseInt(inputLine[j]));
					}
					input.add(r);
				}
				Solution solution = new Solution();
				ArrayList<ArrayList<Integer>> result = solution.diagonal(input);
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
