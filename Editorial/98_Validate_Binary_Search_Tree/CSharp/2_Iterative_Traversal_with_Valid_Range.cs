public class Solution {
    private Stack<TreeNode> stack = new Stack<TreeNode>();
    private Stack<int?> lowerLimits = new Stack<int?>();
    private Stack<int?> upperLimits = new Stack<int?>();

    public void Update(TreeNode root, int? low, int? high) {
        stack.Push(root);
        lowerLimits.Push(low);
        upperLimits.Push(high);
    }

    public bool IsValidBST(TreeNode root) {
        int? low = null, high = null;
        Update(root, low, high);
        while (stack.Count > 0) {
            root = stack.Pop();
            low = lowerLimits.Pop();
            high = upperLimits.Pop();
            if (root == null)
                continue;
            int val = root.val;
            if (low != null && val <= low) {
                return false;
            }

            if (high != null && val >= high) {
                return false;
            }

            Update(root.right, val, high);
            Update(root.left, low, val);
        }

        return true;
    }
}
