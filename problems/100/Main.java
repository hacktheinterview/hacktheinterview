import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
	// X and Y co-ordinates of the points in order.
	// Each point is represented by (X.get(i), Y.get(i))
//-	public int coverPoints(ArrayList<Integer> X, ArrayList<Integer> Y) {
//-	}
//-}



//--SPLIT--
class Solution {
	// X and Y co-ordinates of the points in order.
	// Each point is represented by (X.get(i), Y.get(i))
	public int coverPoints(ArrayList<Integer> X, ArrayList<Integer> Y) {
		int result = 0;
		for (int i = 1; i < X.size(); i++) {
			int a = Math.abs(X.get(i) - X.get(i - 1));
			int b = Math.abs(Y.get(i) - Y.get(i - 1));
			result += Math.abs(b - a);
			result += (a > b) ? b : a;
		}
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
			int n = Integer.parseInt(reader.readLine());
			ArrayList<Integer> X = new ArrayList<Integer>();
			String[] input = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				X.add(Integer.parseInt(input[j]));
			}
			ArrayList<Integer> Y = new ArrayList<Integer>();
			input = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				Y.add(Integer.parseInt(input[j]));
			}
			System.out.println(solution.coverPoints(X, Y));
		}
	}
}
