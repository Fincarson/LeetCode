func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    left_height := maxDepth(root.Left)
    right_height := maxDepth(root.Right)
    return 1 + max(left_height, right_height)
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}
