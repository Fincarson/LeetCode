class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        // always choose right middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1) ++p;
        // preorder traversal: node -> left -> right
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, left, p - 1);
        root->right = helper(nums, p + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
