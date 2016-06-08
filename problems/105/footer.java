
public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");

            int len = Integer.parseInt(inputItems[0]);
            int A[] = new int[len]
            for (int x = 1; x <= len; x++) {
                A[x-1] = Integer.parseInt(inputItems[x]);
            }
            Solution s = new Solution();
            int result = s.minCost(A);
            System.out.println(result);
        }
    }
}
