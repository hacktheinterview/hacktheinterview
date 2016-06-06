// Bad solution. Need to re-write

// TreeNode type
// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; left = null; right = null; }
// }
class Solution {
    ArrayList<Integer> result = new ArrayList<Integer>();

    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // Implement the solution
        _inorder(root);
        return result;
    }


    public void _inorder(TreeNode root) {
        if (root == null)
            return;

        _inorder(root.left);
        result.add(root.val);
        _inorder(root.right);
    }

    private int hasTwoSum(int K) {
        ArrayList<Integer> order = new ArrayList<Integer>();
        order = result;
        if (order.size() <= 1) {
            return 0;
        }
        int start = 0;
        int end = order.size() - 1;
        while (start < end) {
            if (order.get(start) + order.get(end) == K)
                return 1;
            if (order.get(start) + order.get(end) > K)
                end --;
            else
                start++;
        }
        return 0;
    }

    public int isPairPresent(TreeNode root, int K) {
        if (root == null)
            return 0;
        _inorder(root);
        return hasTwoSum(K);
    }
}
