func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    stack := []struct {
        depth int
        node  *TreeNode
    }{{1, root}}
    depth := 0
    for len(stack) != 0 {
        current := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if current.node != nil {
            if depth < current.depth {
                depth = current.depth
            }
            stack = append(stack, struct {
                depth int
                node  *TreeNode
            }{current.depth + 1, current.node.Left})
            stack = append(stack, struct {
                depth int
                node  *TreeNode
            }{current.depth + 1, current.node.Right})
        }
    }
    return depth
}
