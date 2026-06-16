// An already defined Node struct is assumed.
//
//    type Node struct {
//        Val int
//        Left, Right, Next *Node
//    }
func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    // Start with the root node. There are no next pointers
    // that need to be set up on the first level
    leftmost := root
    // Once we reach the final level, we are done
    for leftmost.Left != nil {
        // Iterate the "linked list" starting from the head
        // node and using the Next pointers, establish the
        // corresponding links for the next level
        head := leftmost
        for head != nil {
            // CONNECTION 1
            head.Left.Next = head.Right
            // CONNECTION 2
            if head.Next != nil {
                head.Right.Next = head.Next.Left
            }
            // Progress along the list (nodes on the current level)
            head = head.Next
        }
        // Move onto the next level
        leftmost = leftmost.Left
    }
    return root
}
