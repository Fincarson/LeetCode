struct TreeNode* prev = NULL;
bool inorder(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (!inorder(root->left)) {
        return false;
    }
    if (prev != NULL && root->val <= prev->val) {
        return false;
    }
    prev = root;
    return inorder(root->right);
}
bool isValidBST(struct TreeNode* root) {
    prev = NULL;
    return inorder(root);
}
