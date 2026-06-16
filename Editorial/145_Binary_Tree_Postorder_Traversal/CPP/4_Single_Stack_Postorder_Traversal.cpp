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
        if (root == nullptr) {
            return result;
        }

        // To keep track of the previously processed node
        TreeNode* previousNode = nullptr;
        // Stack to manage the traversal
        stack<TreeNode*> traversalStack;

        // Process nodes until both the root is null and the stack is empty
        while (root != nullptr || !traversalStack.empty()) {
            // Traverse to the leftmost node
            if (root != nullptr) {
                traversalStack.push(root);
                root = root->left;
            } else {
                // Peek at the top node of the stack
                root = traversalStack.top();

                // If there is no right child or the right child was already
                // processed
                if (root->right == nullptr || root->right == previousNode) {
                    result.push_back(root->val);
                    traversalStack.pop();
                    previousNode = root;
                    root = nullptr;  // Ensure we don’t traverse again from this
                                     // node
                } else {
                    // Move to the right child
                    root = root->right;
                }
            }
        }

        return result;
    }
};
