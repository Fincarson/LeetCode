/*
    type Node struct {
        Val int
        Next *Node
        Random *Node
    }
*/
func copyRandomList(head *Node) *Node {
    // HashMap which holds old nodes as keys and new nodes as its values.
    visitedHash := map[*Node]*Node{}
    // A recursive function to copy the node.
    var cloneNode func(node *Node) *Node
    cloneNode = func(node *Node) *Node {
        if node == nil {
            return nil
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if _, ok := visitedHash[node]; ok {
            return visitedHash[node]
        }
        // Create a new node
        // with the value same as old node.
        newNode := &Node{Val: node.Val}
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this would help us avoid them.
        visitedHash[node] = newNode
        // Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        newNode.Next = cloneNode(node.Next)
        newNode.Random = cloneNode(node.Random)
        return newNode
    }
    return cloneNode(head)
}
