class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == NULL) return levels;
        deque<TreeNode*> next_level;
        next_level.push_back(root);
        while (!next_level.empty()) {
            deque<TreeNode*> curr_level = next_level;
            next_level.clear();
            levels.push_back(vector<int>());
            for (TreeNode* node : curr_level) {
                // append the current node value
                levels.back().push_back(node->val);
                // process child nodes for the next level
                if (node->left != NULL) next_level.push_back(node->left);
                if (node->right != NULL) next_level.push_back(node->right);
            }
        }
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
