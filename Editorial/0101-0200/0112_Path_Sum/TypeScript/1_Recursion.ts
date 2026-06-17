function hasPathSum(root: TreeNode | null, sum: number): boolean {
    if (root === null) return false;
    sum -= root.val;
    if (root.left === null && root.right === null)
        // if reach a leaf
        return sum === 0;
    return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
}
