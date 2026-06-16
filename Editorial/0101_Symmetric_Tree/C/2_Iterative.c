// C
bool isSymmetric(struct TreeNode* root) {
    struct TreeNode* q[3030];
    int head = 0;
    int tail = 0;
    q[head++] = root;
    q[head++] = root;
    while (head != tail) {
        struct TreeNode* t1 = q[tail++];
        struct TreeNode* t2 = q[tail++];
        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;
        if (t1->val != t2->val) return false;
        q[head++] = t1->left;
        q[head++] = t2->right;
        q[head++] = t1->right;
        q[head++] = t2->left;
    }
    return true;
}
