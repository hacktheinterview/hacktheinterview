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
            int postorder[] = new int[n];
            int inorder[] = new int[n];
            for (int j = 0; j < n; j++)
                inorder[j] = Integer.parseInt(tokens[j+1]);

            for (int j = 0; j < n; j++)
                postorder[j] = Integer.parseInt(tokens[n+j+1]);

            BinaryTree tree = new BinaryTree();
            Solution s = new Solution();
            TreeNode root = s.constructBinaryTree(inorder, postorder);
            tree.updateRoot(root);
            tree.printTreeToOutputFormat();
        }
    }
}
