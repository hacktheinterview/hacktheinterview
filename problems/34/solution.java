// TreeNode type
// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; left = null; right = null; }
// }
class Solution {
    ArrayList<Integer> result = new ArrayList<Integer>();

    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        // Implement the solution
        _postorder(root);
        return result;
    }


    public void _postorder(TreeNode root) {
        if (root == null)
            return;
        _postorder(root.left);
        _postorder(root.right);
        result.add(root.val);
    }

}
