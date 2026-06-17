class Solution {
public:
    // Hash Set to store node value of the rightmost branch
    unordered_set<int> visited;

    // Do Reverse Postorder Traversal. Assume input "root" as recursive parameter "node"
    TreeNode* correctBinaryTree(TreeNode* root) {
        // If Empty Node, return
        if (root == nullptr) {
            return nullptr;
        }

        // If node.right is already visited, then the node is defective
        // No need to build tree rooted at "node". Replace it with null
        if (root->right != nullptr && visited.count(root->right->val)) {
            return nullptr;
        }

        // Add this node's value to visited
        visited.insert(root->val);

        // Recursively build tree rooted at "node"
        // Build the right subtree first, so that we can explore right to left
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);

        // Return root of built tree
        return root;       
    }
};
