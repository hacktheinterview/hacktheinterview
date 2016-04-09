import java.io.*;
import java.util.*;
import java.lang.*;

//--SPLIT--

//-class Solution {
//-	public void arrange(ArrayList<Integer> a) {
//-	}
//-}


//--SPLIT--
class Solution {
	public void arrange(ArrayList<Integer> a) {
		int n = a.size();
		for (int i=0; i < a.size(); i++) {
			int newVal = a.get(i) + (a.get(a.get(i)) % n) * n;
			a.set(i, newVal);
		}
		// Second Step: Divide all values by n
		for (int i = 0; i < a.size(); i++)
			a.set(i, a.get(i) / n);
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
			ArrayList<Integer> a = new ArrayList<Integer>();
			for (int j = 1; j < inputItems.length; j++) {
				a.add(Integer.parseInt(inputItems[j]));
			}
			solution.arrange(a);
			for (int j = 0; j < a.size(); j++) {
				System.out.print(a.get(j) + " ");
			}
			System.out.println();
		}
	}
}
