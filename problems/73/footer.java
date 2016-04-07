
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		Solution s = new Solution();
		for (int i = 1; i <= cases; i++) {
			String input = reader.readLine();
			int a = Integer.parseInt(input);
			System.out.println(s.primesum(a));
		}
	}
}
