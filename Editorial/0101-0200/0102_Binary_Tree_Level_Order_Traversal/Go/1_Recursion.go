func levelOrder(root *TreeNode) [][]int {
    levels := [][]int{}
    var helper func(*TreeNode, int)
    helper = func(node *TreeNode, level int) {
        if len(levels) == level {
            levels = append(levels, []int{})
        }
        levels[level] = append(levels[level], node.Val)
        if node.Left != nil {
            helper(node.Left, level+1)
        }
        if node.Right != nil {
            helper(node.Right, level+1)
        }
    }
    if root != nil {
        helper(root, 0)
    }
    return levels
}
