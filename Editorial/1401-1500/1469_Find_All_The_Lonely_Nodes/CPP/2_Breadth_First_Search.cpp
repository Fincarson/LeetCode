class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});

        while (!q.empty()) {
            pair<TreeNode*, bool> qFront = q.front();
            q.pop();
            
            TreeNode* currNode = qFront.first;
            bool isLonely = qFront.second;

            if (isLonely) {
                ans.push_back(currNode->val);
            }
            
            if (currNode->right) {
                q.push({currNode->right, currNode->left == NULL});
            }

            if (currNode->left) {
                q.push({currNode->left, currNode->right == NULL});
            }
        }
        
        return ans;
    }
};
