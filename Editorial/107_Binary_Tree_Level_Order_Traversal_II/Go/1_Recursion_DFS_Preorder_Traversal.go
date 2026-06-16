func levelOrderBottom(root *TreeNode) [][]int {
    levels := make([][]int, 0)
    var helper func(node *TreeNode, level int)
    helper = func(node *TreeNode, level int) {
        if node == nil {
            return
        }
        // start the current level
        if len(levels) == level {
            levels = append(levels, []int{})
        }
        // append the current node value
        levels[level] = append(levels[level], node.Val)
        // process child nodes for the next level
        if node.Left != nil {
            helper(node.Left, level+1)
        }
        if node.Right != nil {
            helper(node.Right, level+1)
        }
    }
    helper(root, 0)
    // reverse the levels
    for i := 0; i < len(levels)/2; i++ {
        levels[i], levels[len(levels)-1-i] = levels[len(levels)-1-i], levels[i]
    }
    return levels
}
