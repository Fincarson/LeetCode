void recoverTree(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    struct TreeNode* x = NULL;
    struct TreeNode* y = NULL;
    struct TreeNode* pred = NULL;
    struct TreeNode* node;
    int top = -1;
    while (top >= 0 || root != NULL) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        node = stack[top--];
        if (pred != NULL && node->val < pred->val) {
            y = node;
            if (x == NULL)
                x = pred;
            else
                break;
        }
        pred = node;
        root = node->right;
    }
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}
