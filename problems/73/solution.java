
class Solution {
	public ArrayList<Integer> primesum(int a) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		boolean[] isPrime = primeArray(a);
		for (int i = 2; i < a; i++) {
			int j = a - i;
			if (isPrime[i] && isPrime[j]) {
				result.add(i);
				result.add(j);
				return result;
			}
		}
		return result;
	}

	public boolean[] primeArray(int n) {
		boolean[] isPrime = new boolean[n + 1];
		for (int i = 2; i <= n; i++) {
			isPrime[i] = true;
		}
		for(int i = 2; i <=n; i++) {
			for (int j = 2; i * j <= n; j++) {
				isPrime[i * j] = false;
			}
		}
		return isPrime;
	}
}

