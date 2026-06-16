/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    stack := make([]*TreeNode, 0)
    var prev *TreeNode = nil
    for len(stack) > 0 || root != nil {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        // If next element in inorder traversal
        // is smaller than the previous one
        // that's not BST.
        if prev != nil && root.Val <= prev.Val {
            return false
        }
        prev = root
        root = root.Right
    }
    return true
}
