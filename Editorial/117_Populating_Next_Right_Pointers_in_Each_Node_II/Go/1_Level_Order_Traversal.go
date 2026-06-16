func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    Q := list.New()
    Q.PushBack(root)
    // Outer while loop which iterates over
    // each level
    for Q.Len() > 0 {
        // Note the size of the queue
        size := Q.Len()
        // Iterate over all the nodes on the current level
        for i := 0; i < size; i++ {
            // Pop a node from the front of the queue
            front := Q.Front()
            node := front.Value.(*Node)
            Q.Remove(front)
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if i < size-1 {
                node.Next = Q.Front().Value.(*Node)
            }
            // Add the children, if any, to the back of
            // the queue
            if node.Left != nil {
                Q.PushBack(node.Left)
            }
            if node.Right != nil {
                Q.PushBack(node.Right)
            }
        }
    }
    // Since the tree has now been modified, return the root node
    return root
}
