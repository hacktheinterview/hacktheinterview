
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			String a = reader.readLine();
			Solution solution = new Solution();
			System.out.println(solution.reverseWords(a));
		}
	}
}
