class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t level_size = q.size();
            for (size_t i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                // if it's the given node
                if (curr == u) {
                    if (i == level_size - 1) {
                        return nullptr;
                    } else {
                        return q.front();
                    }
                }

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }
        return nullptr;
    }
};
