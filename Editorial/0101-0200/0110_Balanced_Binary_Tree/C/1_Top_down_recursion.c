// Compute the tree's height via recursion
int height(struct TreeNode* root) {
    // An empty tree has height -1
    if (root == NULL) {
        return -1;
    }
    return 1 + fmax(height(root->left), height(root->right));
}
bool isBalanced(struct TreeNode* root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == NULL) {
        return true;
    }
    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return abs(height(root->left) - height(root->right)) < 2 &&
           isBalanced(root->left) && isBalanced(root->right);
}
