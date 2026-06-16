// C
int dfs(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    // If only one of child is non-null, then go into that recursion.
    if (!root->left) {
        return 1 + dfs(root->right);
    } else if (!root->right) {
        return 1 + dfs(root->left);
    }
    // Both children are non-null, hence call for both children.
    int left_depth = dfs(root->left);
    int right_depth = dfs(root->right);
    return 1 + (left_depth < right_depth ? left_depth : right_depth);
}
int minDepth(struct TreeNode* root) { return dfs(root); }
