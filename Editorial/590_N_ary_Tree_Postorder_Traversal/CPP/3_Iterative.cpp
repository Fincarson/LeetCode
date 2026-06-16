class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        // If the root is nullptr, return the empty vector
        if (root == nullptr) return result;

        stack<Node*> nodeStack;     // Stack for traversal
        stack<Node*> reverseStack;  // Stack to reverse the order

        nodeStack.push(root);

        // Traverse the tree using the nodeStack
        while (!nodeStack.empty()) {
            Node* currentNode = nodeStack.top();
            nodeStack.pop();
            reverseStack.push(currentNode);

            // Push all the children of the current node to nodeStack
            for (Node* child : currentNode->children) {
                nodeStack.push(child);
            }
        }

        // Pop nodes from reverseStack and add their values to the result vector
        while (!reverseStack.empty()) {
            Node* currentNode = reverseStack.top();
            reverseStack.pop();
            result.push_back(currentNode->val);
        }

        return result;
    }
};
