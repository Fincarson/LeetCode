class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        deque<TreeNode*> queue;
        queue.push_back(root);
        vector<int> rightside;

        while (!queue.empty()) {
            int levelLength = queue.size();

            for (int i = 0; i < levelLength; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();

                // if it's the rightmost element
                if (i == levelLength - 1) {
                    rightside.push_back(node->val);
                }

                // add child nodes in the queue
                if (node->left != nullptr) {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.push_back(node->right);
                }
            }
        }
        return rightside;
    }
};
