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
}
*/

public class Solution {
    // Dictionary which holds old nodes as keys and new nodes as its values.
    private Dictionary<Node, Node> visitedHash = new Dictionary<Node, Node>();

    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        // If we have already processed the current node, then we simply return
        // the cloned version of it.
        if (this.visitedHash.ContainsKey(head)) {
            return this.visitedHash[head];
        }

        // Create a new node with the value same as old node. (i.e., copy the
        // node)
        Node node = new Node(head.val, null, null);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this
        // would help us avoid them.
        this.visitedHash[head] = node;
        // Recursively copy the remaining linked list starting once from the
        // next pointer and then from the random pointer. Thus we have two
        // independent recursive calls. Finally we update the next and random
        // pointers for the new node created.
        node.next = this.CopyRandomList(head.next);
        node.random = this.CopyRandomList(head.random);
        return node;
    }
}
