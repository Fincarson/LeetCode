void findTwoSwapped(struct TreeNode *root, struct TreeNode **pred,
                    struct TreeNode **x, struct TreeNode **y) {
    if (root == NULL) return;
    findTwoSwapped(root->left, pred, x, y);
    if (*pred != NULL && root->val < (*pred)->val) {
        *y = root;
        if (*x == NULL)
            *x = *pred;
        else
            return;
    }
    *pred = root;
    findTwoSwapped(root->right, pred, x, y);
}
void recoverTree(struct TreeNode *root) {
    struct TreeNode *pred = NULL, *x = NULL, *y = NULL;
    findTwoSwapped(root, &pred, &x, &y);
    // Swap x and y values
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}
