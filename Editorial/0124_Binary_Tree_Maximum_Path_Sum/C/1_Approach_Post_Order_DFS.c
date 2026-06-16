int max(int a, int b) { return (a > b) ? a : b; }
int gainFromSubtree(struct TreeNode* root, int* maxSum) {
    if (root == NULL) return 0;
    int gainFromLeft = max(0, gainFromSubtree(root->left, maxSum));
    int gainFromRight = max(0, gainFromSubtree(root->right, maxSum));
    *maxSum = max(*maxSum, gainFromLeft + gainFromRight + root->val);
    return max(gainFromLeft + root->val, gainFromRight + root->val);
}
int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    gainFromSubtree(root, &maxSum);
    return maxSum;
}
