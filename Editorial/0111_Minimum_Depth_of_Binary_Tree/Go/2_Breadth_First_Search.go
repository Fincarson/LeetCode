// Golang does not have a built-in queue, we have to emulate it using a slice.
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var q []*TreeNode
    q = append(q, root)
    depth := 1
    for len(q) != 0 {
        qSize := len(q)
        for i := 0; i < qSize; i++ {
            node := q[0]
            q = q[1:]
            // Since we added nodes without checking null, we need to skip them here.
            if node == nil {
                continue
            }
            // The first leaf would be at minimum depth, hence return it.
            if node.Left == nil && node.Right == nil {
                return depth
            }
            q = append(q, node.Left)
            q = append(q, node.Right)
        }
        depth++
    }
    return -1
}
