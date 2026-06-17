bool isValidBST(struct TreeNode* root) {
    struct TreeNode* stack[1000];
    struct TreeNode* prev = NULL;
    int top = -1;
    while (root != NULL || top >= 0) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        if (prev != NULL && root->val <= prev->val) {
            return false;
        }
        prev = root;
        root = root->right;
    }
    return true;
}
