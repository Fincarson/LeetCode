func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    Q := []*Node{root}
    // Outer while loop which iterates over each level
    for len(Q) > 0 {
        // Note  size of the queue
        size := len(Q)
        // Iterate over all the nodes on the current level
        for i := 0; i < size; i++ {
            // Pop a node from the front of the queue
            node := Q[0]
            Q = Q[1:]
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if i < size-1 {
                node.Next = Q[0]
            }
            // Add the children, if any, to the back of
            // the queue
            if node.Left != nil {
                Q = append(Q, node.Left)
            }
            if node.Right != nil {
                Q = append(Q, node.Right)
            }
        }
    }
    // Since the tree has now been modified, return the root node
    return root
}
