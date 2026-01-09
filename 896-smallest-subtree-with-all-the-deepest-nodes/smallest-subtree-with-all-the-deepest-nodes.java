class Solution {
    class Pair {
        int depth;
        TreeNode node;
        Pair(int d, TreeNode n) {
            depth = d;
            node = n;
        }
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }

    private Pair dfs(TreeNode root) {
        if (root == null) return new Pair(0, null);

        Pair left = dfs(root.left);
        Pair right = dfs(root.right);

        if (left.depth > right.depth)
            return new Pair(left.depth + 1, left.node);
        else if (right.depth > left.depth)
            return new Pair(right.depth + 1, right.node);
        else
            return new Pair(left.depth + 1, root);
    }
}
