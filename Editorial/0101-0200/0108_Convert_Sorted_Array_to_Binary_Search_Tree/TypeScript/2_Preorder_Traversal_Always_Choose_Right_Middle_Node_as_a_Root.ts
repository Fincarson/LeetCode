function sortedArrayToBST(nums: number[]): TreeNode | null {
    function helper(left: number, right: number): TreeNode | null {
        if (left > right) return null;
        // always choose right middle node as a root
        let p = Math.floor((left + right) / 2);
        if ((left + right) % 2 === 1) ++p;
        // preorder traversal: node -> left -> right
        const root = new TreeNode(nums[p]);
        root.left = helper(left, p - 1);
        root.right = helper(p + 1, right);
        return root;
    }
    return helper(0, nums.length - 1);
}
