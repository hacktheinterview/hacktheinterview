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

    public int KthSmallest(TreeNode root, int K) {
        if (root == null)
            return 0;
        _inorder(root);
        return result.get(K - 1);
    }
}
