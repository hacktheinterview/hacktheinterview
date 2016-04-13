
	public class Main {
		public static void main(String args[]) throws Exception {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			int cases = Integer.parseInt(reader.readLine());
			for (int i = 1; i <= cases; i++) {
				int a = Integer.parseInt(reader.readLine());
				Solution solution = new Solution();
				ArrayList<ArrayList<Integer>> result = solution.generateMatrix(a);
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
