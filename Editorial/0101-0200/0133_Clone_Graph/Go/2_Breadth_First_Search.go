/**
 * Definition for a Node
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */
func cloneGraph(node *Node) *Node {
    if node == nil {
        return node
    }
    // Hash map to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    visited := make(map[*Node]*Node)
    // Put the first node in the queue
    queue := []*Node{node}
    // Clone the node and put it in the visited map.
    visited[node] = &Node{node.Val, []*Node{}}
    // Start BFS traversal
    for len(queue) > 0 {
        n := queue[0]
        queue = queue[1:]
        // Iterate through all the neighbors of the node
        for _, neighbor := range n.Neighbors {
            if _, ok := visited[neighbor]; !ok {
                // Clone the neighbor and put in the visited, if not present already
                visited[neighbor] = &Node{neighbor.Val, []*Node{}}
                // Add the newly encountered node to the queue.
                queue = append(queue, neighbor)
            }
            // Add the clone of the neighbor to the neighbors of the clone node "n".
            visited[n].Neighbors = append(
                visited[n].Neighbors,
                visited[neighbor],
            )
        }
    }
    // Return the clone of the node from visited.
    return visited[node]
}
