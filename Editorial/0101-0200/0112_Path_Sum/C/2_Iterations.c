bool hasPathSum(struct TreeNode *root, int sum) {
    struct TreeNode *node_stack[1000];
    int sum_stack[1000];
    int stack_size = 0;
    if (root == NULL) return false;
    node_stack[stack_size] = root;
    sum_stack[stack_size++] = sum - root->val;
    while (stack_size > 0) {
        struct TreeNode *node = node_stack[--stack_size];
        sum = sum_stack[stack_size];
        if (node->left == NULL && node->right == NULL && sum == 0) return true;
        if (node->right != NULL) {
            node_stack[stack_size] = node->right;
            sum_stack[stack_size++] = sum - node->right->val;
        }
        if (node->left != NULL) {
            node_stack[stack_size] = node->left;
            sum_stack[stack_size++] = sum - node->left->val;
        }
    }
    return false;
}
