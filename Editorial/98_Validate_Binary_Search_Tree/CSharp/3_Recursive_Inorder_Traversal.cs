public class Solution {
    private int? prev;

    public bool IsValidBST(TreeNode root) {
        prev = null;
        return inorder(root);
    }

    private bool inorder(TreeNode root) {
        if (root == null) {
            return true;
        }

        if (!inorder(root.left)) {
            return false;
        }

        if (prev != null && root.val <= prev) {
            return false;
        }

        prev = root.val;
        return inorder(root.right);
    }
}
