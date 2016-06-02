// TreeNode type
// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; left = null; right = null; }
// }
class Solution {
    ArrayList<Integer> result = new ArrayList<Integer>();

    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        // Implement the solution
        _inorder(root);
        return result;
    }


    public void _inorder(TreeNode root) {
        if (root == null)
            return;
        result.add(root.val);
        _inorder(root.left);
        _inorder(root.right);
    }

}
