public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");
            int n = Integer.parseInt(inputItems[0]);
            ArrayList<Integer> input = new ArrayList<Integer>();
            for (int x = 1; x <= n; x++) {
                input.add(Integer.parseInt(inputItems[x]));
            }

            int A = Integer.parseInt(inputItems[inputItems.length - 2]);
            int B = Integer.parseInt(inputItems[inputItems.length - 1]);

            Solution s = new Solution();

            Solution solution = new Solution();
            int result = solution.paintBoards(A, B, input);
            System.out.println(result);
        }
    }
}
