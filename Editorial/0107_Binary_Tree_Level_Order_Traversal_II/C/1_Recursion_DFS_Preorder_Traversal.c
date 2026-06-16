void helper(struct TreeNode* node, int level, int* returnSize,
            int** columnSizes, int*** levels) {
    // start the current level
    if (*returnSize == level) {
        (*returnSize)++;
        *columnSizes = (int*)realloc(*columnSizes, (*returnSize) * sizeof(int));
        (*columnSizes)[level] = 0;
        *levels = (int**)realloc(*levels, (*returnSize) * sizeof(int*));
        (*levels)[level] = (int*)malloc(1000 * sizeof(int));
    }
    // append the current node value
    (*levels)[level][(*columnSizes)[level]++] = node->val;
    // process child nodes for the next level
    if (node->left != NULL)
        helper(node->left, level + 1, returnSize, columnSizes, levels);
    if (node->right != NULL)
        helper(node->right, level + 1, returnSize, columnSizes, levels);
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize,
                       int** columnSizes) {
    *returnSize = 0;
    *columnSizes = NULL;
    int** levels = NULL;
    if (root != NULL) helper(root, 0, returnSize, columnSizes, &levels);
    // reverse the levels
    for (int i = 0; i < *returnSize / 2; i++) {
        int* tmp = levels[i];
        levels[i] = levels[*returnSize - 1 - i];
        levels[*returnSize - 1 - i] = tmp;
        int tmp_size = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[*returnSize - 1 - i];
        (*columnSizes)[*returnSize - 1 - i] = tmp_size;
    }
    return levels;
}
