struct Pair {
    TreeNode* p;
    TreeNode* q;
};
class Solution {
public:
    Solution() {}
    ~Solution() {}
    bool check(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;  // p and q is null
        if (q == nullptr || p == nullptr)
            return false;  // one of p and q is null
        if (p->val != q->val) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<Pair> deq;
        deq.push({p, q});
        while (!deq.empty()) {
            Pair pos = deq.front();
            deq.pop();
            p = pos.p;
            q = pos.q;
            if (!check(p, q)) return false;
            if (p != nullptr) {
                if (!check(p->left, q->left)) return false;
                deq.push({p->left, q->left});
                if (!check(p->right, q->right)) return false;
                deq.push({p->right, q->right});
            }
        }
        return true;
    }
};
