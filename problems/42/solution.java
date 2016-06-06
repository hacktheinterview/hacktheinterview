// TreeNode type
// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; left = null; right = null; }
// }
class Solution {
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<TreeNode> Q1 = new ArrayList<TreeNode>();
        if (root == null)
            return result;
        int level = 0;
        Q1.add(root);
        while (Q1.size() > 0) {
            ArrayList<TreeNode> Q2 = new ArrayList<TreeNode>();
            ArrayList<Integer> row = new ArrayList<Integer> ();
            int index = 0;
            level++;

            if (level % 2 == 1) {
                index = Q1.size() - 1;
                while (index >= 0) {
                    TreeNode current = Q1.get(index);
                    index--;
                    row.add(current.val);
                    if (current.left != null)
                        Q2.add(current.left);
                    if (current.right != null)
                        Q2.add(current.right);
                }
            } else {
                index = Q1.size() - 1;
                while (index >= 0) {
                    TreeNode current = Q1.get(index);
                    index--;
                    row.add(current.val);
                    if (current.right != null)
                        Q2.add(current.right);
                    if (current.left != null)
                        Q2.add(current.left);
                }

            }
            Q1 = Q2;
            result.add(row);
        }
        return result;
    }

}
