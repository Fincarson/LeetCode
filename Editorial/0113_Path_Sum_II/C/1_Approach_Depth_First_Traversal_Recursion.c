void helper(struct TreeNode* root, int sum, int* path, int depth,
            int** columnSizes, int* returnSize, int*** returnArray) {
    if (root == NULL) return;
    path[depth] = root->val;
    if (root->left == NULL && root->right == NULL && sum == root->val) {
        (*returnArray) =
            (int**)realloc((*returnArray), sizeof(int*) * (*returnSize + 1));
        (*returnArray)[*returnSize] = (int*)calloc(depth + 1, sizeof(int));
        memcpy((*returnArray)[*returnSize], path, sizeof(int) * (depth + 1));
        (*columnSizes) =
            (int*)realloc((*columnSizes), sizeof(int) * (*returnSize + 1));
        (*columnSizes)[*returnSize] = depth + 1;
        (*returnSize)++;
    }
    helper(root->left, sum - root->val, path, depth + 1, columnSizes,
           returnSize, returnArray);
    helper(root->right, sum - root->val, path, depth + 1, columnSizes,
           returnSize, returnArray);
}
int** pathSum(struct TreeNode* root, int sum, int* returnSize,
              int** returnColumnSizes) {
    int** returnArray = (int**)calloc(5000, sizeof(int*));
    int* path = (int*)calloc(5000, sizeof(int));
    (*returnSize) = 0;
    (*returnColumnSizes) = (int*)calloc(5000, sizeof(int));
    helper(root, sum, path, 0, returnColumnSizes, returnSize, &returnArray);
    return returnArray;
}
