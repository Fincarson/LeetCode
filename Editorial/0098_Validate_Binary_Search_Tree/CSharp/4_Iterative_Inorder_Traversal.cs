public class Solution {
    public bool IsValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode prev = null;
        while (stack.Count > 0 || root != null) {
            while (root != null) {
                stack.Push(root);
                root = root.left;
            }

            root = stack.Pop();
            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST.
            if (prev != null && root.val <= prev.val) {
                return false;
            }

            prev = root;
            root = root.right;
        }

        return true;
    }
}
