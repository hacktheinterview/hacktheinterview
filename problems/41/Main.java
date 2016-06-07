import java.io.*;
import java.util.*;
import java.util.LinkedList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; left = null; right = null; }
}
// TreeNode type
// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; left = null; right = null; }
// }
class Solution {
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<TreeNode> Q1 = new ArrayList<TreeNode>();
        if (root == null)
            return result;
        Q1.add(root);
        while (Q1.size() > 0) {
            ArrayList<TreeNode> Q2 = new ArrayList<TreeNode>();
            ArrayList<Integer> row = new ArrayList<Integer> ();
            int index = 0;
            while (index < Q1.size()) {
                TreeNode current = Q1.get(index);
                index++;
                row.add(current.val);
                if (current.left != null)
                    Q2.add(current.left);
                if (current.right != null)
                    Q2.add(current.right);
            }
            Q1 = Q2;
            result.add(row);
        }
        return result;
    }
}

class BinaryTree {
    TreeNode root;
    BinaryTree() {
        this.root = null;
    }

    void printTreeToOutputFormat() {
        StringBuilder sb = new StringBuilder();
        serialize(this.root, sb);
        System.out.println(sb.substring(0, sb.length() - 1));
    }

    private void serialize(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("# ");
            return;
        }
        sb.append(Integer.toString(root.val)).append(" ");
        serialize(root.left, sb);
        serialize(root.right, sb);
    }

    public void deserializeTree(String line) {
        StringTokenizer st = new StringTokenizer(line, " ");
        st.nextToken();
        this.root = constructTree(st);
    }

    private TreeNode constructTree(StringTokenizer st) {
        if (!st.hasMoreTokens()) return null;

        String val = st.nextToken();
        if (val.equals("#")) {
            return null;
        }

        TreeNode tmp = new TreeNode(Integer.parseInt(val));
        tmp.left = constructTree(st);
        tmp.right = constructTree(st);
        return tmp;
    }
}

public class Main {
    private static void print2DArrayList(ArrayList<ArrayList<Integer>> result) {
        System.out.print("[");
        for (int i = 0; i < result.size(); i++) {
            System.out.print("[");
            ArrayList<Integer> row = result.get(i);
            for (int j = 0; j < row.size(); j++) {
                System.out.print(row.get(j));
                System.out.print(",");
            }
            System.out.print("],");
        }
        System.out.println("]");
    }

    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            BinaryTree tree = new BinaryTree();
            tree.deserializeTree(inputLine);
            Solution s = new Solution();
            ArrayList<ArrayList<Integer>> result = s.levelOrder(tree.root);
            print2DArrayList(result);
        }
    }
}
