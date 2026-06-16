typedef struct TreeNode TreeNode;
void swap(TreeNode* a, TreeNode* b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}
void recoverTree(TreeNode* root) {
    TreeNode* x = NULL;
    TreeNode* y = NULL;
    TreeNode* pred = NULL;
    TreeNode* predecessor = NULL;
    while (root != NULL) {
        if (root->left != NULL) {
            predecessor = root->left;
            while (predecessor->right != NULL && predecessor->right != root) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = root;
                root = root->left;
            } else {
                if (pred != NULL && root->val < pred->val) {
                    y = root;
                    if (x == NULL) x = pred;
                }
                pred = root;
                predecessor->right = NULL;
                root = root->right;
            }
        } else {
            if (pred != NULL && root->val < pred->val) {
                y = root;
                if (x == NULL) x = pred;
            }
            pred = root;
            root = root->right;
        }
    }
    swap(x, y);
}
