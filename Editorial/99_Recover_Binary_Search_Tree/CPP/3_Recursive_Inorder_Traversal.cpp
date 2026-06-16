class Solution {
public:
    TreeNode* x = nullptr;     // first node
    TreeNode* y = nullptr;     // second node
    TreeNode* pred = nullptr;  // predecessor node
    void findTwoSwapped(TreeNode* root) {
        if (root == nullptr) return;
        findTwoSwapped(root->left);
        if (pred != nullptr && root->val < pred->val) {
            y = root;
            if (x == nullptr)
                x = pred;
            else
                return;
        }
        pred = root;
        findTwoSwapped(root->right);
    }
    void recoverTree(TreeNode* root) {
        findTwoSwapped(root);
        swap(x->val, y->val);  // C++ standard swap function
    }
};
