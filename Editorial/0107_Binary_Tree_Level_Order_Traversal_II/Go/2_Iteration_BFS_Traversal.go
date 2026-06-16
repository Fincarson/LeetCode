func levelOrderBottom(root *TreeNode) [][]int {
    levels := make([][]int, 0)
    if root == nil {
        return levels
    }
    nextLevel := []*TreeNode{root}
    for len(nextLevel) > 0 {
        currLevel := nextLevel
        nextLevel = make([]*TreeNode, 0)
        levels = append(levels, make([]int, 0))
        for _, node := range currLevel {
            // append the current node value
            levels[len(levels)-1] = append(levels[len(levels)-1], node.Val)
            // process child nodes for the next level
            if node.Left != nil {
                nextLevel = append(nextLevel, node.Left)
            }
            if node.Right != nil {
                nextLevel = append(nextLevel, node.Right)
            }
        }
    }
    // reverse the array in-place
    for i := 0; i < len(levels)/2; i++ {
        levels[i], levels[len(levels)-1-i] = levels[len(levels)-1-i], levels[i]
    }
    return levels
}
