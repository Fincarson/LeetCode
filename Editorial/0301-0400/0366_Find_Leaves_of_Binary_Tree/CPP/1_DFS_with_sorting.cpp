class Solution {
public:
    
    vector<pair<int, int>> pairs;
    
    int getHeight(TreeNode *root) {
        
        // return -1 for null nodes
        if (!root) return -1;
        
        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // collect the pair -> (height, val)
        this->pairs.push_back({currHeight, root->val});
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->pairs.clear();
        
        getHeight(root);
        
        // sort all the (height, val) pairs
        sort(this->pairs.begin(), this->pairs.end());
        
        int n = this->pairs.size(), height = 0, i = 0;
        vector<vector<int>> solution;
        while (i < n) {
            vector<int> nums;
            while (i < n && this->pairs[i].first == height) {
                nums.push_back(this->pairs[i].second);
                i++;
            }
            solution.push_back(nums);
            height++;
        }
        return solution;
    }
};
