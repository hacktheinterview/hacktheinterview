
public class Main {

    private static void printArrayList(ArrayList<Integer> result) {
        for (int k = 0; k < result.size(); k++) {
            System.out.print(result.get(k));
            if (k != result.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

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
			int K = Integer.parseInt(inputItems[len + 1]);
            Solution s = new Solution();
            ArrayList<Integer> result = s.topKFrequent(a, K);
            printArrayList(result);
        }
    }
}
