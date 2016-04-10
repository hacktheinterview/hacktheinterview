public class Main {
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
            Solution solution = new Solution();
            int result = solution.findMin(a);
			System.out.println(result);
        }
    }
}
