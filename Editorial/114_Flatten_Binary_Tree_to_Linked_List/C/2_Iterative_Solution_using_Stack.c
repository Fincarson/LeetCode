struct Pair {
    struct TreeNode* key;
    int value;
};
void flatten(struct TreeNode* root) {
    // Handle the null scenario
    if (!root) {
        return;
    }
    int START = 1, END = 2;
    struct TreeNode* tailNode = NULL;
    struct Pair stack[1000];
    int top = 0;
    stack[top].key = root;
    stack[top++].value = START;
    while (top > 0) {
        struct Pair nodeData = stack[--top];
        struct TreeNode* currentNode = nodeData.key;
        int recursionState = nodeData.value;
        // We reached a leaf node. Record this as a tail
        // node and move on.
        if (!currentNode->left && !currentNode->right) {
            tailNode = currentNode;
            continue;
        }
        // If the node is in the START state, it means we still
        // haven't processed it's left child yet.
        if (recursionState == START) {
            // If the current node has a left child, we add it
            // to the stack AFTER adding the current node again
            // to the stack with the END recursion state.
            if (currentNode->left) {
                stack[top].key = currentNode;
                stack[top++].value = END;
                stack[top].key = currentNode->left;
                stack[top++].value = START;
            } else if (currentNode->right) {
                // In case the current node didn't have a left child
                // we will add it's right child
                stack[top].key = currentNode->right;
                stack[top++].value = START;
            }
        } else {
            // If the current node is in the END recursion state,
            // that means we did process one of its children. Left
            // if it existed, else right.
            struct TreeNode* rightNode = currentNode->right;
            // If there was a left child, there must have been a leaf
            // node and so, we would have set the tailNode
            if (tailNode) {
                // Establish the proper connections.
                tailNode->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = NULL;
                rightNode = tailNode->right;
            }
            if (rightNode) {
                stack[top].key = rightNode;
                stack[top++].value = START;
            }
        }
    }
}
