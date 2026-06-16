struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) return NULL;
    // always choose left middle node as a root
    int p = (left + right) / 2;
    // preorder traversal: node -> left -> right
    struct TreeNode* root = createNode(nums[p]);
    root->left = helper(nums, left, p - 1);
    root->right = helper(nums, p + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // The 0 here is the position of the first element in the array. numsSize -
    // 1 is the position of the last element in the array.
    return helper(nums, 0, numsSize - 1);
}
