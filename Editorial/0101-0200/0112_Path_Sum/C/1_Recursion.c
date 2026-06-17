bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) return false;
    sum -= root->val;
    if (!root->left && !root->right)  // if reach a leaf
        return sum == 0;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
