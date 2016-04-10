
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			Solution solution = new Solution();
			String[] input = reader.readLine().split(" ");
			int n = Integer.parseInt(input[0]);
			ArrayList<Integer> a = new ArrayList<Integer>();
			for (int j = 1; j <= n; j++) {
				a.add(Integer.parseInt(input[j]));
			}
			ArrayList<Integer> result = solution.repeatedNumber(a); 
			System.out.println(result.get(0) + " " + result.get(1));
		}
	}
}
