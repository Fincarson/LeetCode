/*
// Definition for a Node.

    type Node struct {
        Val int
        Neighbors []*Node
    }
*/
func cloneGraph(node *Node) *Node {
    if node == nil {
        return node
    }
    visited := make(map[*Node]*Node)
    return dfs(node, visited)
}

func dfs(node *Node, visited map[*Node]*Node) *Node {
    if node == nil {
        return node
    }
    if value, ok := visited[node]; ok {
        return value
    }
    cloneNode := &Node{
        Val:       node.Val,
        Neighbors: make([]*Node, len(node.Neighbors)),
    }
    visited[node] = cloneNode
    for i, neighbor := range node.Neighbors {
        cloneNode.Neighbors[i] = dfs(neighbor, visited)
    }
    return cloneNode
}
