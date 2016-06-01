import java.io.*;
import java.util.*;

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
    public static ListNode addTwoLinkedLists(ListNode H1, ListNode H2) {
        // Implement the solution
        return null;
    }
}


class BinaryTree {
    TreeNode root;
    BinaryTree() {
        this.root = null;
    }

    void deserializeTree(String[] inputItems) {
        if (inputItems.length == 1) {
            this.root = null; return;
        }

        int index = 1;
        this.root = new TreeNode(Integer.parseInt(inputItems[index++]));
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while (index < inputItems.size()) {
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

            int numNodes1 = Integer.parseInt(inputItems[0]);
            BinaryTree tree = new BinaryTree();
            tree.deserializeTree(inputItems);
        }

    }
}
