/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node* cloneNode = new Node(node->val, {});
        // The key is original node and value being the clone node.
        visited[node] = cloneNode;
        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned
        // node.
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};
