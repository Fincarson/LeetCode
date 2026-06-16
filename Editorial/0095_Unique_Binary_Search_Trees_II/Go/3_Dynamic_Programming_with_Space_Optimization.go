func generateTrees(n int) (outs []*TreeNode) {
    dp := make([][]*TreeNode, n+1)
    dp[0] = append(dp[0], nil)
    for numberOfNodes := 1; numberOfNodes <= n; numberOfNodes++ {
        for i := 1; i <= numberOfNodes; i++ {
            j := numberOfNodes - i
            for _, left := range dp[i-1] {
                for _, right := range dp[j] {
                    root := &TreeNode{i, left, clone(right, i)}
                    dp[numberOfNodes] = append(dp[numberOfNodes], root)
                }
            }
        }
    }
    return dp[n]
}

func clone(node *TreeNode, offset int) *TreeNode {
    if node == nil {
        return nil
    }
    clonedNode := &TreeNode{node.Val + offset, nil, nil}
    clonedNode.Left = clone(node.Left, offset)
    clonedNode.Right = clone(node.Right, offset)
    return clonedNode
}
