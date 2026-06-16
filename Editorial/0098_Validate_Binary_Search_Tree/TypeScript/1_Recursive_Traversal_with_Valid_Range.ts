function isValidBST(
    root: TreeNode | null,
    low: number | null = null,
    high: number | null = null,
): boolean {
    // Empty trees are valid BSTs.
    if (root === null) return true;
    // The current node's value must be between low and high.
    if (
        (low !== null && root.val <= low) ||
        (high !== null && root.val >= high)
    )
        return false;
    // The left and right subtree must also be valid.
    return (
        isValidBST(root.right, root.val, high) &&
        isValidBST(root.left, low, root.val)
    );
}
