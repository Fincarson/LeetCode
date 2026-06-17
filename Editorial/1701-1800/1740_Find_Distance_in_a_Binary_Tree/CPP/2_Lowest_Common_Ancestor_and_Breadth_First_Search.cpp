class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // Find the lowest common ancestor of p and q.
        TreeNode* lca = findLCA(root, p, q);

        // Start the BFS process with lca as the root.
        queue<TreeNode*> bfs;
        bfs.push(lca);
        int distance = 0, depth = 0;
        bool foundp = 0, foundq = 0;
        while (!bfs.empty() or (foundp == 0 and foundq == 0)) {
            int size = bfs.size();

            // Traverse all nodes at the height level.
            while (size--) {
                TreeNode* front = bfs.front();
                bfs.pop();
                // Add the current height to the distance if p or q is found.
                if (front->val == p) {
                    distance += depth;
                    foundp = 1;
                }
                if (front->val == q) {
                    distance += depth;
                    foundq = 1;
                }
                // Add the children to the queue. These will be traversed in the
                // next height level.
                if (front->left != nullptr) {
                    bfs.push(front->left);
                }
                if (front->right != nullptr) {
                    bfs.push(front->right);
                }
            }
            depth++;
        }

        return distance;
    }

private:
    // Function to find the lca of two nodes recursively.
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (root == nullptr or root->val == p or root->val == q) {
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left != nullptr and right != nullptr) {
            return root;
        }
        return (left != nullptr) ? left : right;
    }
};
