// C#

public class Solution {
    private int Dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // If only one of child is non-null, then go into that recursion.
        if (root.left == null) {
            return 1 + Dfs(root.right);
        } else if (root.right == null) {
            return 1 + Dfs(root.left);
        }

        // Both children are non-null, hence call for both children.
        return 1 + Math.Min(Dfs(root.left), Dfs(root.right));
    }

    public int MinDepth(TreeNode root) {
        return Dfs(root);
    }
}
