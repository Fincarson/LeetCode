class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr != nullptr) {
                // if it's the given node
                if (curr == u) {
                    return q.front();
                }

                // add child nodes in the queue
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            } else {
                // add a senitel to mark end of level
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
        }
        return nullptr;
    }
};
