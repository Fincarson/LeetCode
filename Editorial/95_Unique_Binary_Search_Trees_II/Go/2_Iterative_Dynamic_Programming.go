func generateTrees(n int) []*TreeNode {
    if n == 0 {
        return []*TreeNode{}
    }
    return generateSubtrees(1, n)
}

func generateSubtrees(start int, end int) []*TreeNode {
    var list []*TreeNode
    if start > end {
        list = append(list, nil)
        return list
    }
    for i := start; i <= end; i++ {
        left := generateSubtrees(start, i-1)
        right := generateSubtrees(i+1, end)
        for _, leftNode := range left {
            for _, rightNode := range right {
                node := &TreeNode{Val: i}
                node.Left = leftNode
                node.Right = rightNode
                list = append(list, node)
            }
        }
    }
    return list
}
