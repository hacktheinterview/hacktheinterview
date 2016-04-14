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
    public static TreeNode addTwoLinkedLists(TreeNode H1, TreeNode H2) {
        // Implement the solution
        return null;
    }
}


class BinaryTree {
    TreeNode root;
    BinaryTree() {
        this.root = null;
    }

    void printTreeToOutputFormat() {
        ArrayList<String> ret = new ArrayList<String>();
        if (this.root == null) {
            System.out.println();
            return;
        }

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(this.root);
        while(q.peek() != null) {
            TreeNode tmp = q.remove();
            if (tmp == null) {
                ret.add("#");
                continue;
            }
            ret.add(Integer.toString(tmp.val));

            q.add(tmp.left);
            q.add(tmp.right);
        }

        for (int i = 0; i < ret.size(); i++) {
            System.out.print(ret.get(i));
            if (i != ret.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    void deserializeTree(String[] inputItems) {
        if (inputItems.length == 1) {
            this.root = null;
            return;
        }

        int index = 1;
        this.root = new TreeNode(Integer.parseInt(inputItems[index++]));
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while (index < inputItems.length) {
            TreeNode tmp = q.remove();

            if (inputItems[index].equals("#")) {
                tmp.left = null;
            } else {
                int val = Integer.parseInt(inputItems[index]);
                TreeNode leftNode = new TreeNode(val);
                tmp.left = leftNode;
                q.add(leftNode);
            }
            index++;

            if (inputItems[index].equals("#")) {
                tmp.right = null;
            } else {
                int val = Integer.parseInt(inputItems[index]);
                TreeNode rightNode = new TreeNode(val);
                tmp.right = rightNode;
                q.add(rightNode);
            }
            index++;
        }
    }
}

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            String inputItems[] = inputLine.split(" ");
            BinaryTree tree = new BinaryTree();
            tree.deserializeTree(inputItems);
            tree.printTreeToOutputFormat();
        }

    }
}
