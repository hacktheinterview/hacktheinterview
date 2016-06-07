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
    public static void main(String args[]) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());

        for (int i = 1; i <= cases; i++) {
            String inputLine = reader.readLine();
            BinaryTree tree = new BinaryTree();
            tree.deserializeTree(inputLine);
            Solution s = new Solution();
            System.out.println(s.maxSumPathRootToLeaf(tree.root));
        }
    }
}
