class Solution {
public:
    // Track previous node while doing inorder traversal.
    TreeNode* previous = NULL;
    
    // Function to check if given tree is a valid Binary Search Tree or not.
    bool isValidBST(TreeNode* root) {
        // An empty tree is a valid Binary Search Tree.
        if (!root) {
            return true;
        }

        // If left subtree is not a valid BST return false.
        if(!isValidBST(root->left)) {
            return false;
        }
        
        // If current node's value is not greater than the previous 
        // node's value in the in-order traversal return false.
        if (previous && previous->val >= root->val) {
            return false;
        }
        
        // Update previous node to current node.
        previous = root;
        
        // If right subtree is not a valid BST return false.
        return isValidBST(root->right);
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        // Add nodes in left and right subtree.
        // Add 1 and return total size.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        // Set previous node to NULL initially.
        previous = NULL;
        
        // If current subtree is a validBST, its children will have smaller size BST.
        if (isValidBST(root)) {
            return countNodes(root);
        }
        
        // Find BST in left and right subtrees of current nodes.
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
