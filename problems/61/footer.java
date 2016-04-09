
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution solution = new Solution();
		for (int i = 1; i <= cases; i++) {
			String s = reader.readLine();
			System.out.println(solution.isPalindrome(s));
		}
	}
}
