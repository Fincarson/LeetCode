class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Base case: if root is null, return an array with two null elements
        if (!root) {
            return {nullptr, nullptr};
        }

        // If root's value is greater than target,
        // recursively split left subtree
        if (root->val > target) {
            auto left = splitBST(root->left, target);
            // Attach the right part of the split to root's left subtree
            root->left = left[1];
            return {left[0], root};
        } else {
            // Otherwise, recursively split right subtree
            auto right = splitBST(root->right, target);
            // Attach the left part of the split to root's right subtree
            root->right = right[0];
            return {root, right[1]};
        }
    }
};
