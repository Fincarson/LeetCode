typedef struct {
    struct TreeNode* node;
    int partialSum;
} StackNode;
int sumNumbers(struct TreeNode* root) {
    if (root == NULL) return 0;
    StackNode myStack[10000] = {0};
    int top = -1;
    myStack[++top] = (StackNode){root, root->val};
    int rootToLeaf = 0;
    while (top >= 0) {
        StackNode p = myStack[top--];
        root = p.node;
        int currNumber = p.partialSum;
        if (root->left == NULL && root->right == NULL)
            rootToLeaf += currNumber;
        else {
            if (root->right != NULL)
                myStack[++top] = (StackNode){
                    root->right, currNumber * 10 + root->right->val};
            if (root->left != NULL)
                myStack[++top] =
                    (StackNode){root->left, currNumber * 10 + root->left->val};
        }
    }
    return rootToLeaf;
}
