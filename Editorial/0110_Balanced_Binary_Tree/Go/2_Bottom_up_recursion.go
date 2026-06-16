type TreeInfo struct {
    height   int
    balanced bool
}

func abs(a int) int {
    if a < 0 {
        return -1 * a
    }
    return a
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Returns whether the tree at root is balanced, along with the tree's height.
func isBalancedTreeHelper(root *TreeNode) TreeInfo {
    if root == nil {
        return TreeInfo{-1, true}
    }
    left := isBalancedTreeHelper(root.Left)
    if !left.balanced {
        return TreeInfo{-1, false}
    }
    right := isBalancedTreeHelper(root.Right)
    if !right.balanced {
        return TreeInfo{-1, false}
    }
    if abs(left.height-right.height) < 2 {
        return TreeInfo{max(left.height, right.height) + 1, true}
    }
    return TreeInfo{-1, false}
}

func isBalanced(root *TreeNode) bool {
    return isBalancedTreeHelper(root).balanced
}
