int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    int** res = malloc(sizeof(int*));
    *returnColumnSizes = malloc(sizeof(int));
    *returnSize = 0;
    if (root == NULL) return res;
    struct TreeNode* queue[10000];
    int front = 0, rear = -1, lastLevelNode = 0, cnt = 1;
    queue[++rear] = root;
    while (cnt > 0) {
        int* level = malloc(sizeof(int) * cnt);
        *returnColumnSizes =
            realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        (*returnColumnSizes)[*returnSize] = cnt;
        for (int i = 0; i < cnt; i++) {
            struct TreeNode* node = queue[front++];
            level[i] = node->val;
            if (node->left != NULL) queue[++rear] = node->left;
            if (node->right != NULL) queue[++rear] = node->right;
        }
        res = realloc(res, sizeof(int*) * (*returnSize + 1));
        res[(*returnSize)++] = level;
        cnt = rear - lastLevelNode;
        lastLevelNode = rear;
    }
    return res;
}
