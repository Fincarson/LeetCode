/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }
    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    private Dictionary<Node, Node> visited = new Dictionary<Node, Node>();

    public Node CloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.ContainsKey(node)) {
            return visited[node];
        }

        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node cloneNode = new Node(node.val, new List<Node>());
        // The key is original node and value being the clone node.
        visited[node] = cloneNode;
        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned
        // node.
        foreach (Node neighbor in node.neighbors) {
            cloneNode.neighbors.Add(CloneGraph(neighbor));
        }

        return cloneNode;
    }
}
