/*
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flattenTree(node *TreeNode) *TreeNode {
    // Handle the null scenario
    if node == nil {
        return nil
    }
    // For a leaf node, we simply return the
    // node as is.
    if node.Left == nil && node.Right == nil {
        return node
    }
    // Recursively flatten the left subtree
    leftTail := flattenTree(node.Left)
    // Recursively flatten the right subtree
    rightTail := flattenTree(node.Right)
    // If there was a left subtree, we shuffle the connections
    // around so that there is nothing on the left side
    // anymore.
    if leftTail != nil {
        leftTail.Right = node.Right
        node.Right = node.Left
        node.Left = nil
    }
    // We need to return the "rightmost" node after we are
    // done wiring the new connections.
    if rightTail != nil {
        return rightTail
    } else {
        return leftTail
    }
}

func flatten(root *TreeNode) {
    flattenTree(root)
}
