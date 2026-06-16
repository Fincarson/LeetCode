func hasPathSum(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }
    nodeStack := []*TreeNode{}
    sumStack := []int{}
    nodeStack = append(nodeStack, root)
    sumStack = append(sumStack, sum-root.Val)
    for len(nodeStack) > 0 {
        lastIdx := len(nodeStack) - 1
        currentNode := nodeStack[lastIdx]
        nodeStack = nodeStack[:lastIdx]
        currSum := sumStack[lastIdx]
        sumStack = sumStack[:lastIdx]
        if currentNode.Left == nil && currentNode.Right == nil && currSum == 0 {
            return true
        }
        if currentNode.Right != nil {
            nodeStack = append(nodeStack, currentNode.Right)
            sumStack = append(sumStack, currSum-currentNode.Right.Val)
        }
        if currentNode.Left != nil {
            nodeStack = append(nodeStack, currentNode.Left)
            sumStack = append(sumStack, currSum-currentNode.Left.Val)
        }
    }
    return false
}
