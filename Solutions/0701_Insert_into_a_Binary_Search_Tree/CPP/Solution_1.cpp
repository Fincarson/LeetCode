class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode *newNode = new TreeNode();
            newNode->val = val;
            return newNode;
        } else if(val < root->val){
            root->left = insertIntoBST(root->left, val);
            return root;
        } else {
            root->right = insertIntoBST(root->right, val);
            return root;
        }
        return root;
    }
};