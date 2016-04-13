
class Solution {
	public ArrayList<ArrayList<Integer>> generateMatrix(int a) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < a; i++) {
			ArrayList<Integer> arr = new ArrayList<Integer>();
			result.add(arr);
			for (int j = 0; j < a; j++) {
				arr.add(0);
			}
		}
		int n = 1, numLevels = (a - 1) / 2, i = 0, j = 0;
		for (int level = 0; level <= numLevels; level++) {
			int size = a - 2 * level;
			if (size == 1) {
				ArrayList<Integer> arr = result.get(level);
				arr.set(level, n);
				n++;
				continue;
			}
			for (int side = 0; side < 4; side++) {
				for (int x = 0; x < size - 1; x++) {
					if (side == 0) {
						i = level; j = level;
						j += x;
					} else if (side == 1) {
						i = level; j = a - level - 1;
						i += x;
					} else if (side == 2) {
						i = a - level - 1; j = a - level - 1;
						j -= x;
					} else {
						i = a - level - 1; j = level;
						i -= x;
					}
					ArrayList<Integer> arr = result.get(i);
					arr.set(j, n);
					n++;
				}
			}
		}
		return result;
	}
}
	