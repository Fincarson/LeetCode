public class Solution {
    public TreeNode LcaDeepestLeaves(TreeNode root) {
        return dfs(root).Item1;
    }

    private Tuple<TreeNode, int> dfs(TreeNode root) {
        if (root == null) {
            return new Tuple<TreeNode, int>(null, 0);
        }

        Tuple<TreeNode, int> left = dfs(root.left);
        Tuple<TreeNode, int> right = dfs(root.right);

        if (left.Item2 > right.Item2) {
            return new Tuple<TreeNode, int>(left.Item1, left.Item2 + 1);
        }
        if (left.Item2 < right.Item2) {
            return new Tuple<TreeNode, int>(right.Item1, right.Item2 + 1);
        }
        return new Tuple<TreeNode, int>(root, left.Item2 + 1);
    }
}
