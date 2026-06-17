class Solution {
public:
    void DFS(TreeNode* root, bool isLonely, vector<int>& ans) {
        if (!root) {
            return;
        }
        
        if (isLonely) {
            ans.push_back(root->val);
        }
        
        DFS(root->left, root->right == NULL, ans);
        DFS(root->right, root->left == NULL, ans);
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        DFS(root, false, ans);
        
        return ans;
    }
};
