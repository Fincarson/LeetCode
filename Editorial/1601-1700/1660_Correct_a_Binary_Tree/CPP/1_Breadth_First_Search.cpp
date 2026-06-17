class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        // Queue for BFS. Every element stores [node, parent]
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        // Traverse Level by Level
        while (!q.empty()) {
            // Nodes in the current level
            int n = q.size();

            // Hash Set to store nodes of the current level
            unordered_set<TreeNode*> visited;

            // Traverse all nodes in the current level
            for (int i = 0; i < n; i++) {
                // Pop the node and its parent from the queue
                auto [node, parent] = q.front();
                q.pop();
                
                // If node.right is already visited, then the node is defective
                if (visited.count(node->right)) {
                    // Replace the child of the node's parent with null and return the root
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    return root;
                }

                // Add node to visited
                visited.insert(node);

                // Add child in queue for traversal in next level
                // They won't get popped in this level because of "n"
                // Add the right child first, so that we can explore right to left
                if (node->right) {
                    q.push({node->right, node});
                }
                if (node->left) {
                    q.push({node->left, node});
                }
            }
        }

        // For the sake of compilation
        return root;  
    }
};
