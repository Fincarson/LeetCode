class Solution {
public:
    void flatten(TreeNode* root) {
        // Handle the null scenario
        if (!root) {
            return;
        }
        TreeNode* node = root;
        while (node != nullptr) {
            // If the node has a left child
            if (node->left != nullptr) {
                // Find the rightmost node
                TreeNode* rightmost = node->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                // rewire the connections
                rightmost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            // move on to the right side of the tree
            node = node->right;
        }
    }
};
