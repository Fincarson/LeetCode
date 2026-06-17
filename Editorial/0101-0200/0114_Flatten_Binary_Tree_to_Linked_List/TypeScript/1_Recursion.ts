/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function flattenTree(node: TreeNode | null): TreeNode | null {
    // Handle the null scenario
    if (node == null) {
        return null;
    }
    // For a leaf node, we simply return the
    // node as is.
    if (node.left == null && node.right == null) {
        return node;
    }
    // Recursive flatten for the left subtree
    let leftTail = flattenTree(node.left);
    // Recursive flatten for the right subtree
    let rightTail = flattenTree(node.right);
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
function flatten(root: TreeNode | null): void {
    flattenTree(root);
}
