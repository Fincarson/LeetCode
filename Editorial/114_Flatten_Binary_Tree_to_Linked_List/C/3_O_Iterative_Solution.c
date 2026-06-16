struct TreeNode* flatten(struct TreeNode* root) {
    // Handle the null scenario
    if (!root) return NULL;
    struct TreeNode* node = root;
    while (node != NULL) {
        // If the node has a left child
        if (node->left != NULL) {
            // Find the rightmost node
            struct TreeNode* rightmost = node->left;
            while (rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            // rewire the connections
            rightmost->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        // move on to the right side of the tree
        node = node->right;
    }
    return root;
}
