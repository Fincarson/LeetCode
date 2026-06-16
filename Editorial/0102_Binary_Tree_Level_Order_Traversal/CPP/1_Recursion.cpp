class Solution {
public:
    vector<vector<int>> levels;
    void helper(TreeNode* node, int level) {
        if (levels.size() == level) levels.push_back(vector<int>());
        levels[level].push_back(node->val);
        if (node->left != nullptr) helper(node->left, level + 1);
        if (node->right != nullptr) helper(node->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return levels;
        helper(root, 0);
        return levels;
    }
};
