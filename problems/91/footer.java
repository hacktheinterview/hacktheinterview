
	public class Main {
		public static void main(String args[]) throws Exception {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			int cases = Integer.parseInt(reader.readLine());
			for (int testCase = 1; testCase <= cases; testCase++) {
				int a = Integer.parseInt(reader.readLine());
				ArrayList<ArrayList<Integer>> input = new ArrayList<ArrayList<Integer>>();
				for (int i = 0; i < a; i++) {
					String[] inputLine = reader.readLine().split(" ");
					ArrayList<Integer> r = new ArrayList<Integer>();
					for (int j = 0; j < inputLine.length; j++) {
						r.add(Integer.parseInt(inputLine[j]));
					}
					input.add(r);
				}
				Solution solution = new Solution();
				ArrayList<ArrayList<Integer>> result = solution.diagonal(input);
				for (int j = 0; j < result.size(); j++) {
					ArrayList<Integer> arrayList = result.get(j);
					for (int k = 0; k < arrayList.size(); k++) {
						System.out.print(arrayList.get(k) + " ");
					}
					System.out.println();
				}
			}
		}
	}
