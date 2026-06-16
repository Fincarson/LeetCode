class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode *x = NULL, *y = NULL, *pred = NULL;
        while (!stack.empty() || root != NULL) {
            while (root != NULL) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (pred != NULL && root->val < pred->val) {
                y = root;
                if (x == NULL)
                    x = pred;
                else
                    break;
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};
