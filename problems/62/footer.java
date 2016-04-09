
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
