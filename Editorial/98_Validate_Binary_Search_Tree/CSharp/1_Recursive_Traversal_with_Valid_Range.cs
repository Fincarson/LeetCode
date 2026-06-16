public class Solution {
    public bool Validate(TreeNode root, int? low, int? high) {
        // Empty trees are valid BSTs.
        if (root == null) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low.HasValue && root.val <= low.Value) ||
            (high.HasValue && root.val >= high.Value)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return Validate(root.right, root.val, high) &&
               Validate(root.left, low, root.val);
    }

    public bool IsValidBST(TreeNode root) {
        return Validate(root, null, null);
    }
}
