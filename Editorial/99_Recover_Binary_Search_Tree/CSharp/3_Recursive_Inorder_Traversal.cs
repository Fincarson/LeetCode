public class Solution {
    private TreeNode x = null, y = null, pred = null;

    private void FindTwoSwapped(TreeNode root) {
        if (root == null)
            return;
        FindTwoSwapped(root.left);
        if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null)
                x = pred;
            else
                return;
        }

        pred = root;
        FindTwoSwapped(root.right);
    }

    public void RecoverTree(TreeNode root) {
        FindTwoSwapped(root);
        int tmp = x.val;
        x.val = y.val;
        y.val = tmp;
    }
}
