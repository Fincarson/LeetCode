/*
// Definition for a Node.

    type Node struct {
        Val    int
        Next   *Node
        Random *Node
    }
*/
func copyRandomList(head *Node) *Node {
    // Creating a visited map to hold old node reference as key and new node reference as the value
    visited := make(map[*Node]*Node)
    getClonedNode := func(node *Node) *Node {
        // If node exists then
        if node != nil {
            // Check if it's in the visited map
            if _, ok := visited[node]; ok {
                // If it's in the visited map then return the new node reference from the map
                return visited[node]
            } else {
                // Otherwise create a new node, save the reference in the visited map and return it.
                newNode := &Node{Val: node.Val}
                visited[node] = newNode
                return newNode
            }
        }
        return nil
    }
    if head == nil {
        return nil
    }
    oldNode := head
    // Creating the new head node.
    newNode := &Node{Val: oldNode.Val}
    visited[oldNode] = newNode
    // Iterate on the linked list until all nodes are cloned.
    for oldNode != nil {
        // Get the clones of the nodes referenced by random and next pointers.
        newNode.Random = getClonedNode(oldNode.Random)
        newNode.Next = getClonedNode(oldNode.Next)
        // Move one step ahead in the linked list.
        oldNode = oldNode.Next
        newNode = newNode.Next
    }
    return visited[head]
}
