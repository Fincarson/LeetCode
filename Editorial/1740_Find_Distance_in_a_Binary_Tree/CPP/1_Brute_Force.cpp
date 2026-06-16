class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // Find the lowest common ancestor of p and q.
        TreeNode* lca = findLCA(root, p, q);
        return depth(lca, p) + depth(lca, q);
    }

private:
    // Function to find the LCA of the given nodes.
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

    // Function to find the depth of the node with respect to LCA.
    int depth(TreeNode* root, int target, int currentDepth = 0) {
        // Node not found
        if (root == NULL) {
            return -1;
        }
        if (root->val == target) {
            return currentDepth;
        }

        // Check left subtree
        int leftDepth = depth(root->left, target, currentDepth + 1);
        if (leftDepth != -1) {
            return leftDepth;
        }

        // If not in left subtree, it is guaranteed to be in right subtree
        return depth(root->right, target, currentDepth + 1);
    }
};
