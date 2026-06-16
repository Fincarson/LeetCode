public class Solution {
    private int maxSum = int.MinValue;

    public int MaxPathSum(TreeNode root) {
        GainFromSubtree(root);
        return maxSum;
    }

    // post order traversal of subtree rooted at `root`
    private int GainFromSubtree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // add the path sum from left subtree. Note that if the path
        // sum is negative, we can ignore it, or count it as 0.
        // This is the reason we use `Math.Max` here.
        int gainFromLeft = Math.Max(GainFromSubtree(root.left), 0);
        // add the path sum from right subtree. 0 if negative
        int gainFromRight = Math.Max(GainFromSubtree(root.right), 0);
        maxSum = Math.Max(maxSum, gainFromLeft + gainFromRight + root.val);
        // return the max sum for a path starting at the root of subtree
        return Math.Max(gainFromLeft + root.val, gainFromRight + root.val);
    }
}
