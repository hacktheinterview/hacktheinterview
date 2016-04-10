public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");
            int n = Integer.parseInt(inputItems[0]);
            Solution solution = new Solution();
            int result = solution.squareRoot(n);
			System.out.println(result);
        }
    }
}
