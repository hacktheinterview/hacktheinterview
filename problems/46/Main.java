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
    public TreeNode constructBinaryTree(int[] preorder, int[] inorder) {
        // Implement the solution
        int preStart = 0;
        int preEnd = preorder.length - 1;
        int inStart = 0;
        int inEnd = inorder.length - 1;

        return construct(preorder, preStart, preEnd, inorder, inStart, inEnd);
    }

    public TreeNode construct(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd){
        if(preStart>preEnd||inStart>inEnd){
            return null;
        }

        int val = preorder[preStart];
        TreeNode p = new TreeNode(val);

        //find parent element index from inorder
        int k=0;
        for(int i=0; i<inorder.length; i++){
            if(val == inorder[i]){
                k=i;
                break;
            }
        }

        p.left = construct(preorder, preStart+1, preStart+(k-inStart), inorder, inStart, k-1);
        p.right= construct(preorder, preStart+(k-inStart)+1, preEnd, inorder, k+1 , inEnd);

        return p;
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

    public void updateRoot(TreeNode node) {
        this.root = node;
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
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String[] tokens = inputLine.split(" ");

            int n = Integer.parseInt(tokens[0]);
            int inorder[] = new int[n];
            int preorder[] = new int[n];
            for (int j = 0; j < n; j++)
                preorder[j] = Integer.parseInt(tokens[j+1]);

            for (int j = 0; j < n; j++)
                inorder[j] = Integer.parseInt(tokens[n+j+1]);

            BinaryTree tree = new BinaryTree();
            Solution s = new Solution();
            TreeNode root = s.constructBinaryTree(preorder, inorder);
            tree.updateRoot(root);
            tree.printTreeToOutputFormat();
        }
    }
}
