class Solution {
public:
    void flatten(TreeNode* root) {
        // Handle the null scenario
        if (root == NULL) {
            return;
        }
        int START = 1, END = 2;
        TreeNode* tailNode = nullptr;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, START));
        while (!stk.empty()) {
            pair<TreeNode*, int> nodeData = stk.top();
            stk.pop();
            TreeNode* currentNode = nodeData.first;
            int recursionState = nodeData.second;
            // We reached a leaf node. Record this as a tail
            // node and move on.
            if (currentNode->left == NULL && currentNode->right == NULL) {
                tailNode = currentNode;
                continue;
            }
            // If the node is in the START state, it means we still
            // haven't processed it's left child yet.
            if (recursionState == START) {
                // If the current node has a left child, we add it
                // to the stack AFTER adding the current node again
                // to the stack with the END recursion state.
                if (currentNode->left != NULL) {
                    stk.push(make_pair(currentNode, END));
                    stk.push(make_pair(currentNode->left, START));
                } else if (currentNode->right != NULL) {
                    // In case the current node didn't have a left child
                    // we will add it's right child
                    stk.push(make_pair(currentNode->right, START));
                }
            } else {
                // If the current node is in the END recursion state,
                // that means we did process one of it's children. Left
                // if it existed, else right.
                TreeNode* rightNode = currentNode->right;
                // If there was a left child, there must have been a leaf
                // node and so, we would have set the tailNode
                if (tailNode != NULL) {
                    // Establish the proper connections.
                    tailNode->right = currentNode->right;
                    currentNode->right = currentNode->left;
                    currentNode->left = NULL;
                    rightNode = tailNode->right;
                }
                if (rightNode != NULL) {
                    stk.push(make_pair(rightNode, START));
                }
            }
        }
    }
};
