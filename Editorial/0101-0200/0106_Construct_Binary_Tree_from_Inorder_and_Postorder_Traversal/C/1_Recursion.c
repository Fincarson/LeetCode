struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder,
                           int postorderSize) {
    if (inorderSize == 0) {
        return NULL;
    }
    int i;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == postorder[postorderSize - 1]) {
            break;
        }
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i,
                            postorderSize - i - 1);
    return root;
}
