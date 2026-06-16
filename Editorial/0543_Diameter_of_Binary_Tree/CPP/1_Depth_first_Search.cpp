class Solution {
private:
    int diameter;

    int longestPath(TreeNode* node) {
        if (node == nullptr) return -1;

        // Recursively find the longest path in both left and right children
        int leftPath = longestPath(node->left);
        int rightPath = longestPath(node->right);

        // Update the diameter if leftPath + rightPath + 2 is greater
        diameter = std::max(diameter, leftPath + rightPath + 2);

        // Return the longest one between leftPath and rightPath + 1
        return std::max(leftPath, rightPath) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
};
