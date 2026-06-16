typedef struct {
    struct TreeNode* node;
    long low;
    long high;
} StackNode;
void update(struct TreeNode* root, long low, long high, StackNode* stack,
            int* top) {
    if (root == NULL) return;
    stack[++(*top)] = (StackNode){root, low, high};
}
bool isValidBST(struct TreeNode* root) {
    StackNode stack[10000];
    int top = -1;
    long lower = LONG_MIN, upper = LONG_MAX;
    update(root, lower, upper, stack, &top);
    while (top >= 0) {
        StackNode tmp = stack[top--];
        root = tmp.node;
        if (root == NULL) continue;
        long val = root->val;
        if (val <= tmp.low || val >= tmp.high) return false;
        update(root->right, val, tmp.high, stack, &top);
        update(root->left, tmp.low, val, stack, &top);
    }
    return true;
}
