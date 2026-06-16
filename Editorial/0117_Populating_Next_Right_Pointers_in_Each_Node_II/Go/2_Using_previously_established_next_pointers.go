func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    // The root node is the only node on the first level
    // and hence its the leftmost node for that level
    leftmost := root
    var prev *Node = nil
    var curr *Node = nil
    // We have no idea about the structure of the tree,
    // so, we keep going until we do find the last level.
    // The nodes on the last level won't have any children
    for leftmost != nil {
        // "prev" tracks the latest node on the "next" level
        // while "curr" tracks the latest node on the current
        // level.
        prev = nil
        curr = leftmost
        // We reset this so that we can re-assign it to the leftmost
        // node of the next level. Also, if there isn't one, this
        // would help break us out of the outermost loop.
        leftmost = nil
        // Iterate on the nodes in the current level using
        // the next pointers already established.
        for curr != nil {
            // Process both the children and update the prev
            // and leftmost pointers as necessary.
            prev, leftmost = processChild(curr.Left, prev, leftmost)
            prev, leftmost = processChild(curr.Right, prev, leftmost)
            // Move onto the next node.
            curr = curr.Next
        }
    }
    return root
}

func processChild(childNode *Node, prev *Node, leftmost *Node) (*Node, *Node) {
    if childNode != nil {
        // If the "prev" pointer is alread set i.e. if we
        // already found atleast one node on the next level,
        // setup its next pointer
        if prev != nil {
            prev.Next = childNode
        } else {
            // Else it means this child node is the first node
            // we have encountered on the next level, so, we
            // set the leftmost pointer
            leftmost = childNode
        }
        prev = childNode
    }
    return prev, leftmost
}
