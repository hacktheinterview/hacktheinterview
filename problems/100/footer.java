
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
