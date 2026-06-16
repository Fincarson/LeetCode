public class Solution {
    public void Swap(ref TreeNode a, ref TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }

    public void RecoverTree(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode x = null, y = null, pred = null;
        while (stack.Count != 0 || root != null) {
            while (root != null) {
                stack.Push(root);
                root = root.left;
            }

            root = stack.Pop();
            if (pred != null && root.val < pred.val) {
                y = root;
                if (x == null)
                    x = pred;
                else
                    break;
            }

            pred = root;
            root = root.right;
        }

        Swap(ref x, ref y);
    }
}
