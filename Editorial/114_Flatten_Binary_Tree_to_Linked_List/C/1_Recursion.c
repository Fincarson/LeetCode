/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* flattenTree(struct TreeNode* node) {
    // Handle the null scenario
    if (!node) {
        return NULL;
    }
    // For a leaf node, we simply return the
    // node as is.
    if (!node->left && !node->right) {
        return node;
    }
    // Recursively flatten the left subtree
    struct TreeNode* leftTail = flattenTree(node->left);
    // Recursively flatten the right subtree
    struct TreeNode* rightTail = flattenTree(node->right);
    // If there was a left subtree, we shuffle the connections
    // around so that there is nothing on the left side
    // anymore.
    if (leftTail) {
        leftTail->right = node->right;
        node->right = node->left;
        node->left = NULL;
    }
    // We need to return the "rightmost" node after we are
    // done wiring the new connections.
    return rightTail ? rightTail : leftTail;
}
void flatten(struct TreeNode* root) { flattenTree(root); }
