int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}
