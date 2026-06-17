function sortedArrayToBST(nums: number[]): TreeNode | null {
    return helper(nums, 0, nums.length - 1);
}
function helper(nums: number[], left: number, right: number): TreeNode | null {
    if (left > right) {
        return null;
    }
    var p = Math.floor((left + right) / 2);
    var root = new TreeNode(nums[p], null, null);
    root.left = helper(nums, left, p - 1);
    root.right = helper(nums, p + 1, right);
    return root;
}
