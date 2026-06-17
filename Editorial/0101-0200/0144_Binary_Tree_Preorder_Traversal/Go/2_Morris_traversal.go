func preorderTraversal(root *TreeNode) []int {
    var output []int
    node := root
    for node != nil {
        if node.Left == nil {
            output = append(output, node.Val)
            node = node.Right
        } else {
            predecessor := node.Left
            for predecessor.Right != nil && predecessor.Right != node {
                predecessor = predecessor.Right
            }
            if predecessor.Right == nil {
                output = append(output, node.Val)
                predecessor.Right = node
                node = node.Left
            } else {
                predecessor.Right = nil
                node = node.Right
            }
        }
    }
    return output
}
