/*
// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
  Node(int _val, Node* _next, Node* _random)
      : val{_val}, next{_next}, random{_random} {};
};
*/
class Solution {
private:
    // Visited dictionary to hold old node reference as key and new node
    // reference as the value
    unordered_map<Node*, Node*> visited;

public:
    Node* getClonedNode(Node* node) {
        // If node exists then
        if (node) {
            // Check if its in the visited map
            if (visited.find(node) != visited.end()) {
                // If its in the visited map then return the new node reference
                // from the map
                return visited[node];
            } else {
                // Otherwise create a new node, save the reference in the
                // visited map and return it.
                visited[node] = new Node(node->val, NULL, NULL);
                return visited[node];
            }
        }
        return NULL;
    }
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* oldNode = head;
        // Creating the new head node.
        Node* newNode = new Node(oldNode->val);
        this->visited[oldNode] = newNode;
        // Iterate on the linked list until all nodes are cloned.
        while (oldNode != NULL) {
            // Get the clones of the nodes referenced by random and next
            // pointers.
            newNode->random = this->getClonedNode(oldNode->random);
            newNode->next = this->getClonedNode(oldNode->next);
            // Move one step ahead in the linked list.
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return this->visited[head];
    }
};
