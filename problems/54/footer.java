public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String tokens = inputLine.split(" ");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[0]);
            Solution solution = new Solution();
            int result = solution.rangeBitwiseAnd(a, b);
			System.out.println(result);
        }
    }
}
