class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == nullptr) {
            return nullptr;
        }
        // note that here we use a deque instead of a queue
        // because deque offers the clear() method, while queue
        // does not
        deque<TreeNode*> next_level;
        next_level.push_back(root);

        while (!next_level.empty()) {
            // prepare for next level
            deque<TreeNode*> curr_level(next_level);
            next_level.clear();

            while (!curr_level.empty()) {
                TreeNode* node = curr_level.front();
                curr_level.pop_front();

                if (node == u) {
                    return (curr_level.empty() ? nullptr : curr_level.front());
                }

                // add child nodes of the current level
                // in the queue for the next level
                if (node->left != nullptr) {
                    next_level.push_back(node->left);
                }
                if (node->right != nullptr) {
                    next_level.push_back(node->right);
                }
            }
        }
        return nullptr;
    }
};
