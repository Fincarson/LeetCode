class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // p and q are both null
        if (!p && !q) return true;
        // one of p and q is null
        if (!q || !p) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};
