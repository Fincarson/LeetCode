// C symbolic Node structure for the Leetcode Playground environment
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
void preorder(struct TreeNode* r, int currNumber, int* rootToLeaf) {
    if (r != NULL) {
        currNumber = currNumber * 10 + r->val;
        // if it's a leaf, update root-to-leaf sum
        if (r->left == NULL && r->right == NULL) *rootToLeaf += currNumber;
        preorder(r->left, currNumber, rootToLeaf);
        preorder(r->right, currNumber, rootToLeaf);
    }
}
int sumNumbers(struct TreeNode* root) {
    int rootToLeaf = 0;
    preorder(root, 0, &rootToLeaf);
    return rootToLeaf;
}
