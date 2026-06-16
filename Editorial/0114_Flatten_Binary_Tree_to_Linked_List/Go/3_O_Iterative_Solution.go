func flatten(root *TreeNode) {
    // Handle the null scenario
    if root == nil {
        return
    }
    node := root
    for node != nil {
        // If the node has a left child
        if node.Left != nil {
            // Find the rightmost node
            rightmost := node.Left
            for rightmost.Right != nil {
                rightmost = rightmost.Right
            }
            // rewire the connections
            rightmost.Right = node.Right
            node.Right = node.Left
            node.Left = nil
        }
        // move on to the right side of the tree
        node = node.Right
    }
}
