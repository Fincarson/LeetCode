struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) return NULL;
    int p = (left + right) / 2;
    if ((left + right) % 2 == 1) p += rand() % 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[p];
    root->left = helper(nums, left, p - 1);
    root->right = helper(nums, p + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}
