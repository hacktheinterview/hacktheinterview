public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();

            long n = Integer.parseLong(inputLine);
            Solution solution = new Solution();
            long result = solution.reverseBits(n);
			System.out.println(result);
        }
    }
}
