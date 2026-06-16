public class Solution {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        // p and q are both null
        if (p == null && q == null)
            return true;
        // one of p and q is null
        if (q == null || p == null)
            return false;
        if (p.val != q.val)
            return false;
        return IsSameTree(p.right, q.right) && IsSameTree(p.left, q.left);
    }
}
