/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    public Node(int _val, Node _next, Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

public class Solution {
    private Dictionary<Node, Node> visited = new Dictionary<Node, Node>();

    public Node GetClonedNode(Node node) {
        if (node != null) {
            if (visited.ContainsKey(node)) {
                return visited[node];
            } else {
                visited[node] = new Node(node.val, null, null);
                return visited[node];
            }
        }

        return null;
    }

    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node oldNode = head;
        Node newNode = new Node(oldNode.val, null, null);
        visited[oldNode] = newNode;
        while (oldNode != null) {
            newNode.random = this.GetClonedNode(oldNode.random);
            newNode.next = this.GetClonedNode(oldNode.next);
            oldNode = oldNode.next;
            newNode = newNode.next;
        }

        return visited[head];
    }
}
