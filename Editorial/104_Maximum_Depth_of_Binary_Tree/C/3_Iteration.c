struct Pair {
    struct TreeNode* node;
    int depth;
};
struct Pair* pair_create(struct TreeNode* node, int depth) {
    struct Pair* pair = malloc(sizeof(struct Pair));
    pair->node = node;
    pair->depth = depth;
    return pair;
}
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct Pair** stack = malloc(10000 * sizeof(struct TreeNode*));
    int top = 0;
    stack[top++] = pair_create(root, 1);
    int max_depth = 0;
    while (top != 0) {
        struct Pair* pair = stack[--top];
        int c_depth = pair->depth;
        struct TreeNode* c_node = pair->node;
        max_depth = c_depth > max_depth ? c_depth : max_depth;
        free(pair);
        if (c_node->left != NULL) {
            stack[top++] = pair_create(c_node->left, c_depth + 1);
        }
        if (c_node->right != NULL) {
            stack[top++] = pair_create(c_node->right, c_depth + 1);
        }
    }
    free(stack);
    return max_depth;
}
