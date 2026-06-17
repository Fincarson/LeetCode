var sortedArrayToBST = function (nums) {
    let helper = function (left, right) {
        if (left > right) return null;
        let p = Math.floor((left + right) / 2);
        if ((left + right) % 2 == 1) p += Math.floor(Math.random() * 2);
        let root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    };
    return helper(0, nums.length - 1);
};
