class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int rootToLeaf = 0, currNumber = 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 0));
        while (!stk.empty()) {
            pair<TreeNode*, int> p = stk.top();
            stk.pop();
            root = p.first;
            currNumber = p.second;
            if (root != nullptr) {
                currNumber = currNumber * 10 + root->val;
                // if it's a leaf, update root-to-leaf sum
                if (root->left == nullptr && root->right == nullptr) {
                    rootToLeaf += currNumber;
                } else {
                    stk.push(make_pair(root->right, currNumber));
                    stk.push(make_pair(root->left, currNumber));
                }
            }
        }
        return rootToLeaf;
    }
};
