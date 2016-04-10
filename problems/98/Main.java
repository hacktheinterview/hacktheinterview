import java.io.*;
import java.util.*;

//--SPLIT--

//-class Solution {
//-	public ArrayList<Integer> plusOne(ArrayList<Integer> a) {
//-	}
//-}

//--SPLIT--
class Solution {
	public ArrayList<Integer> plusOne(ArrayList<Integer> a) {
	    ArrayList<Integer> result = new ArrayList<Integer>();
	    int carry = 0;
	    for (int i = a.size() - 1; i >= 0; i--) {
	        int x = a.get(i) + carry;
	        if (i == a.size() - 1) {
	            x += 1;
	        }
	        carry = x / 10;
	        result.add(x % 10);
	    }
	    if (carry == 1) {
	        result.add(carry);
	    }
	    Collections.reverse(result);
	    while (result.get(0) == 0) {
	        result.remove(0);
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
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");

            int len = Integer.parseInt(inputItems[0]);
            ArrayList<Integer> a = new ArrayList<Integer>();
            for (int x = 1; x <= len; x++) {
                a.add(Integer.parseInt(inputItems[x]));
            }

            Solution solution = new Solution();
            ArrayList<Integer> result = solution.plusOne(a);
            for (int j = 0; j < result.size(); j++) {
                System.out.print(result.get(j) + " ");
            }
            System.out.println();
        }
    }
}
