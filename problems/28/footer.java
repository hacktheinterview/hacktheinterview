public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int t = 1; t <= cases; t++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");
            int x = 0;
            int rows = Integer.parseInt(inputItems[x++]);
            int cols = Integer.parseInt(inputItems[x++]);
            int matrix[][] = new int[rows][cols];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = Integer.parseInt(inputItems[x++]);
                }
            }

            int K = Integer.parseInt(inputItems[x]);
            Solution s = new Solution();

            Solution solution = new Solution();
            int result = solution.searchMatrix(matrix, K);
            System.out.println(result);
        }
    }
}
