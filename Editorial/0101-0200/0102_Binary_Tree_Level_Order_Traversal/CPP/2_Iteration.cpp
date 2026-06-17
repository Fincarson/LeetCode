class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == NULL) return levels;
        deque<TreeNode*> queue;
        queue.push_back(root);
        int level = 0;
        while (!queue.empty()) {
            // start the current level
            levels.push_back({});
            // number of elements in the current level
            int level_length = queue.size();
            for (int i = 0; i < level_length; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();
                // fulfill the current level
                levels[level].push_back(node->val);
                // add child nodes of the current level
                // in the queue for the next level
                if (node->left != NULL) queue.push_back(node->left);
                if (node->right != NULL) queue.push_back(node->right);
            }
            // go to next level
            level++;
        }
        return levels;
    }
};
