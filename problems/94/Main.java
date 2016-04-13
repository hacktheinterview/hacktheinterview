import java.io.*;
import java.util.*;

//--SPLIT--

//-class Solution {
//-	public ArrayList<Integer> getRow(int a) {
//-	}
//-}

//--SPLIT--
class Solution {
	public ArrayList<Integer> getRow(int a) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		result.add(1);
		
		for (int r = 1; r <= a; r++) {
			int next = (result.get(r - 1) * (a  + 1 - r)) / r;
			result.add(next);
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
            ArrayList<Integer> result = solution.getRow(a);
            for (int j = 0; j < result.size(); j++) {
                System.out.print(result.get(j) + " ");
            }
            System.out.println();
        }
    }
}
