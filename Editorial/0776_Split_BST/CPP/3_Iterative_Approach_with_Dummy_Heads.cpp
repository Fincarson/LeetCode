class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Create dummy nodes to hold the split tree parts
        TreeNode* dummySm = new TreeNode(0);
        TreeNode* curSm = dummySm;
        TreeNode* dummyLg = new TreeNode(0);
        TreeNode* curLg = dummyLg;

        // Start traversal from the root
        TreeNode* current = root;
        TreeNode* nextNode = nullptr;

        while (current != nullptr) {
            if (current->val <= target) {
                // Attach the current node to the tree
                // with values less than or equal to the target
                curSm->right = current;
                curSm = current;

                // Move to the right subtree
                nextNode = current->right;

                // Clear the right pointer of current node
                curSm->right = nullptr;

                current = nextNode;
            } else {
                // Attach the current node to the tree
                // with values greather to the target
                curLg->left = current;
                curLg = current;

                // Move to the left subtree
                nextNode = current->left;

                // Clear the left pointer of current node
                curLg->left = nullptr;

                current = nextNode;
            }
        }

        // Return the split parts as a vector
        return {dummySm->right, dummyLg->left};
    }
};
