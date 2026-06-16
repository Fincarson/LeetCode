class Solution {
public:
    // The function definition
    void recurseTree(TreeNode* node, int remainingSum, vector<int>& pathNodes,
                     vector<vector<int>>& pathsList) {
        if (node == NULL) {
            return;
        }
        // Add the current node to the path's list
        pathNodes.push_back(node->val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (remainingSum == node->val && node->left == NULL &&
            node->right == NULL) {
            pathsList.push_back(vector<int>(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            this->recurseTree(node->left, remainingSum - node->val, pathNodes,
                              pathsList);
            this->recurseTree(node->right, remainingSum - node->val, pathNodes,
                              pathsList);
        }
        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> pathsList;
        vector<int> pathNodes;
        this->recurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
    }
};
