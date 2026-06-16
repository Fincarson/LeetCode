/**
 * Definition for a Node
 * public class Node {
 *     public int val;
 *     public IList<Node> neighbors;
 *
 *     public Node() {
 *         val = 0;
 *         neighbors = new List<Node>();
 *     }
 *
 *     public Node(int _val) {
 *         val = _val;
 *         neighbors = new List<Node>();
 *     }
 *
 *     public Node(int _val, List<Node> _neighbors) {
 *         val = _val;
 *         neighbors = _neighbors;
 *     }
 * }
 */
public class Solution {
    public Node CloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // Hash map to save the visited node and it's respective clone
        // as key and value respectively. This helps to avoid cycles.
        Dictionary<Node, Node> visited = new Dictionary<Node, Node>();
        // Put the first node in the queue
        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(node);
        // Clone the node and put it in the visited dictionary.
        visited[node] = new Node(node.val, new List<Node>());
        // Start BFS traversal
        while (queue.Count > 0) {
            // Pop a node say "n" from the from the front of the queue.
            Node n = queue.Dequeue();
            // Iterate through all the neighbors of the node "n"
            foreach (Node neighbor in n.neighbors) {
                if (!visited.ContainsKey(neighbor)) {
                    // Clone the neighbor and put in the visited, if not present
                    // already
                    visited[neighbor] =
                        new Node(neighbor.val, new List<Node>());
                    // Add the newly encountered node to the queue.
                    queue.Enqueue(neighbor);
                }

                // Add the clone of the neighbor to the neighbors of the clone
                // node "n".
                visited[n].neighbors.Add(visited[neighbor]);
            }
        }

        // Return the clone of the node from visited.
        return visited[node];
    }
}
