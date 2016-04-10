
class Solution {
	public ArrayList<Integer> plusOne(ArrayList<Integer> a) {
	    ArrayList<Integer> result = new ArrayList<Integer>();
	    int carry = 0;
	    for (int i = a.size() - 1; i >= 0; i--) {
	        int x = a.get(i) + carry;
	        if (i == a.size() - 1) {
	            x += 1;
	        }
	        carry = x / 10;
	        result.add(x % 10);
	    }
	    if (carry == 1) {
	        result.add(carry);
	    }
	    Collections.reverse(result);
	    while (result.get(0) == 0) {
	        result.remove(0);
	    }
	    return result;
	}
}

