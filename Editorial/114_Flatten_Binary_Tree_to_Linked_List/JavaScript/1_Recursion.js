/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flattenTree = function (node) {
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
    let leftTail = flattenTree(node.left);
    // Recursively flatten the right subtree
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
};
var flatten = function (root) {
    flattenTree(root);
};
