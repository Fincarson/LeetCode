bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // p and q are both null
    if (p == NULL && q == NULL) return true;
    // one of p and q is null
    if (q == NULL || p == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}
