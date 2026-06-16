bool validate(struct TreeNode* root, struct TreeNode* low,
              struct TreeNode* high) {
    // Empty trees are valid BSTs.
    if (root == NULL) {
        return true;
    }
    // The current node's value must be between low and high.
    if ((low != NULL && root->val <= low->val) ||
        (high != NULL && root->val >= high->val)) {
        return false;
    }
    // The left and right subtree must also be valid.
    return validate(root->right, root, high) && validate(root->left, low, root);
}
bool isValidBST(struct TreeNode* root) { return validate(root, NULL, NULL); }
