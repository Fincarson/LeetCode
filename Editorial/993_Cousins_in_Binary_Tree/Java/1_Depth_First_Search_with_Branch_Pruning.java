/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    // To save the depth of the first node.
    int recordedDepth = -1;
    boolean isCousin = false;

    private boolean dfs(TreeNode node, int depth, int x, int y) {

        if (node == null) {
            return false;
        }

        // Don't go beyond the depth restricted by the first node found.
        if (this.recordedDepth != -1 && depth > this.recordedDepth) {
            return false;
        }

        if (node.val == x || node.val == y) {
            if (this.recordedDepth == -1) {
                // Save depth for the first node found.
                this.recordedDepth = depth;
            }
            // Return true, if the second node is found at the same depth.
            return this.recordedDepth == depth;
        }

        boolean left = dfs(node.left, depth + 1, x, y);
        boolean right = dfs(node.right, depth + 1, x, y);

        // this.recordedDepth != depth + 1 would ensure node x and y are not
        // immediate child nodes, otherwise they would become siblings.
        if (left && right && this.recordedDepth != depth + 1) {
            this.isCousin = true;
        }
        return left || right;
    }
    public boolean isCousins(TreeNode root, int x, int y) {

        // Recurse the tree to find x and y
        dfs(root, 0, x, y);
        return this.isCousin;
    }
}
