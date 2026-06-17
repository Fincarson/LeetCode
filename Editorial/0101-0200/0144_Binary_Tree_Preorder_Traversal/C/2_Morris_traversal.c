int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* output = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    struct TreeNode* node = root;
    while (node != NULL) {
        if (node->left == NULL) {
            output[(*returnSize)++] = node->val;
            node = node->right;
        } else {
            struct TreeNode* predecessor = node->left;
            while (predecessor->right != NULL && predecessor->right != node) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                output[(*returnSize)++] = node->val;
                predecessor->right = node;
                node = node->left;
            } else {
                predecessor->right = NULL;
                node = node->right;
            }
        }
    }
    return output;
}
