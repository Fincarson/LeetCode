class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int currentLevelSum = root->val;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int nextLevelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                // Update node value to cousin sum.
                currentNode->val = currentLevelSum - currentNode->val;

                // Calculate sibling sum.
                int siblingSum =
                    (currentNode->left != nullptr ? currentNode->left->val
                                                  : 0) +
                    (currentNode->right != nullptr ? currentNode->right->val
                                                   : 0);

                if (currentNode->left != nullptr) {
                    nextLevelSum +=
                        currentNode->left->val;  // Accumulate next level sum.
                    currentNode->left->val =
                        siblingSum;  // Update left child's value.
                    nodeQueue.push(
                        currentNode->left);  // Add to queue for next level.
                }
                if (currentNode->right != nullptr) {
                    nextLevelSum +=
                        currentNode->right->val;  // Accumulate next level sum.
                    currentNode->right->val =
                        siblingSum;  // Update right child's value.
                    nodeQueue.push(
                        currentNode->right);  // Add to queue for next level.
                }
            }

            currentLevelSum = nextLevelSum;  // Update current level sum
                                             // for next iteration.
        }
        return root;
    }
};
