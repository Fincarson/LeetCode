class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return vector<int>();

        queue<TreeNode*> queue;
        queue.push(root);
        queue.push(NULL);
        TreeNode *prev, *curr = root;
        vector<int> rightside;

        while (!queue.empty()) {
            prev = curr;
            curr = queue.front();
            queue.pop();

            while (curr != NULL) {
                // add child nodes in the queue
                if (curr->left != NULL) {
                    queue.push(curr->left);
                }
                if (curr->right != NULL) {
                    queue.push(curr->right);
                }

                prev = curr;
                curr = queue.front();
                queue.pop();
            }

            // the current level is finished
            // and prev is its rightmost element
            rightside.push_back(prev->val);

            // add a sentinel to mark the end
            // of the next level
            if (!queue.empty()) queue.push(NULL);
        }
        return rightside;
    }
};
