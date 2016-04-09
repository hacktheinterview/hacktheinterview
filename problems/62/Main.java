import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public int uniquePaths(int a, int b) {
//-	}
//-}


//--SPLIT--
class Solution {
	public int uniquePaths(int a, int b) {
		int[][] result = new int[a][b];
		for (int i = 0; i < a; i++) {
			result[i][0] = 1;
		}
		for (int j = 0; j < b; j++) {
			result[0][j] = 1;
		}
		for (int i = 1; i < a; i++) {
			for (int j = 1; j < b; j++) {
				result[i][j] = result[i - 1][j] + result[i][j - 1];
			}
		}
		return result[a - 1][b - 1];
	}
}



//--SPLIT--
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution solution = new Solution();
		for (int i = 1; i <= cases; i++) {
			String inputItems[] = reader.readLine().split(" ");
			int a = Integer.parseInt(inputItems[0]);
			int b = Integer.parseInt(inputItems[1]);
			System.out.println(solution.uniquePaths(a, b));
		}
	}
}
