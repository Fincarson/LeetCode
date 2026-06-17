var isValidBST = function (root, low = null, high = null) {
    // Empty trees are valid BSTs.
    if (!root) return true;
    // The current node's value must be between low and high.
    if ((low != null && root.val <= low) || (high != null && root.val >= high))
        return false;
    // The left and right subtree must also be valid.
    return (
        isValidBST(root.right, root.val, high) &&
        isValidBST(root.left, low, root.val)
    );
};
