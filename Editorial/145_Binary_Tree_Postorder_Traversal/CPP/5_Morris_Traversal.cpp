/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        // If the root is null, return an empty list
        if (root == NULL) {
            return result;
        }

        // Create a dummy node to simplify edge cases
        TreeNode dummy = -1;
        TreeNode* dummyNode = &dummy;
        TreeNode* predecessor = NULL;
        dummyNode->left = root;
        root = dummyNode;

        // Traverse the tree
        while (root != NULL) {
            // If the current node has a left child
            if (root->left != NULL) {
                predecessor = root->left;

                // Find the rightmost node in the left subtree or the thread
                // back to the current node
                while (predecessor->right != NULL &&
                       predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // Create a thread if it doesn't exist
                if (predecessor->right == NULL) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // Process the nodes in the left subtree
                    TreeNode* node = predecessor;
                    reverseSubtreeLinks(root->left, predecessor);

                    // Add nodes from right to left
                    while (node != root->left) {
                        result.push_back(node->val);
                        node = node->right;
                    }

                    result.push_back(node->val);  // Add root.left's value
                    reverseSubtreeLinks(predecessor, root->left);
                    predecessor->right = NULL;
                    root = root->right;
                }
            } else {
                // Move to the right child if there's no left child
                root = root->right;
            }
        }

        return result;
    }

    void reverseSubtreeLinks(TreeNode* startNode, TreeNode* endNode) {
        if (startNode == endNode) {
            return;  // If the start and end nodes are the same, no need to
                     // reverse
        }

        TreeNode* prev = NULL;
        TreeNode* current = startNode;
        TreeNode* next = NULL;

        // Reverse the direction of the pointers in the subtree
        while (current != endNode) {
            next = current->right;
            current->right = prev;
            prev = current;
            current = next;
        }

        // Reverse the last node
        current->right = prev;
    }
};
