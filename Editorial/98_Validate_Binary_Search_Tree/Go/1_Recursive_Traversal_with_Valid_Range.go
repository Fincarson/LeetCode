func validate(root *TreeNode, low *int, high *int) bool {
    // Empty trees are valid BSTs.
    if root == nil {
        return true
    }
    // The current node's value must be between low and high.
    if (low != nil && root.Val <= *low) || (high != nil && root.Val >= *high) {
        return false
    }
    // The left and right subtree must also be valid.
    return validate(root.Right, &root.Val, high) &&
        validate(root.Left, low, &root.Val)
}

func isValidBST(root *TreeNode) bool {
    return validate(root, nil, nil)
}
