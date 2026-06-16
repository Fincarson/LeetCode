class Solution {
public:   
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the friend
                TreeNode* friendNode = curr->left;
                while (friendNode->right != nullptr) {
                    friendNode = friendNode->right;
                }
                
                friendNode->right = curr;
                
                // Delete the edge after using it
                TreeNode* left = curr->left;
                curr->left = nullptr;
                curr = left;
            } else {
                // Handle the current node
                int num = curr->val;
                if (num == currNum) {
                    currStreak++;
                } else {
                    currStreak = 1;
                    currNum = num;
                }

                if (currStreak > maxStreak) {
                    ans = {};
                    maxStreak = currStreak;
                }

                if (currStreak == maxStreak) {
                    ans.push_back(num);
                }
                
                curr = curr->right;
            }
        }
        
        return ans;
    }
};
