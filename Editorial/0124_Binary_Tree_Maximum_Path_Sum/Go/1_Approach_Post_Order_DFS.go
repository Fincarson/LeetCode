func gainFromSubtree(root *TreeNode, maxSum *int) int {
    if root == nil {
        return 0
    }
    gainFromLeft := max(gainFromSubtree(root.Left, maxSum), 0)
    gainFromRight := max(gainFromSubtree(root.Right, maxSum), 0)
    *maxSum = max(*maxSum, gainFromLeft+gainFromRight+root.Val)
    return max(gainFromLeft+root.Val, gainFromRight+root.Val)
}

func maxPathSum(root *TreeNode) int {
    maxSum := math.MinInt32
    gainFromSubtree(root, &maxSum)
    return maxSum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
