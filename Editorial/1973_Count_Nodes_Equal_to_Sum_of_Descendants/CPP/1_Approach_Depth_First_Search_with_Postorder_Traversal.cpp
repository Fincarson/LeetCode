class Solution {
public:
    int count;
    
    long countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        long left = countNodes(root->left);
        long right = countNodes(root->right);
        
        if (root->val == left + right) {
            count++;
        }
        
        return left + right + root->val;
    }
    
    int equalToDescendants(TreeNode* root) {
        countNodes(root);
        return count;
    }
};
