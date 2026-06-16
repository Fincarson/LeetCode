type Item struct {
    Node  *TreeNode
    Level int
}

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    // The queue that contains the next nodes to visit, along with the level/depth that each node is located.
    nextItems := make([]Item, 0)
    maxDepth := 0
    nextItems = append(nextItems, Item{Node: root, Level: 0})
    for len(nextItems) > 0 {
        nextItem := nextItems[0]
        nextItems = nextItems[1:]
        nextLevel := nextItem.Level + 1
        if nextLevel > maxDepth {
            maxDepth = nextLevel
        }
        // Add the nodes to visit in the following recursive calls.
        if nextItem.Node.Left != nil {
            nextItems = append(
                nextItems,
                Item{Node: nextItem.Node.Left, Level: nextLevel},
            )
        }
        if nextItem.Node.Right != nil {
            nextItems = append(
                nextItems,
                Item{Node: nextItem.Node.Right, Level: nextLevel},
            )
        }
    }
    return maxDepth
}
