/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private TreeNode FlattenTree(TreeNode node) {
        // Handle the null scenario
        if (node == null) {
            return null;
        }

        // For a leaf node, we simply return the
        // node as is.
        if (node.left == null && node.right == null) {
            return node;
        }

        // Recursively flatten the left subtree
        TreeNode leftTail = FlattenTree(node.left);
        // Recursively flatten the right subtree
        TreeNode rightTail = FlattenTree(node.right);
        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != null) {
            leftTail.right = node.right;
            node.right = node.left;
            node.left = null;
        }

        // We need to return the "rightmost" node after we are
        // done wiring the new connections.
        return rightTail == null ? leftTail : rightTail;
    }

    public void Flatten(TreeNode root) {
        FlattenTree(root);
    }
}
