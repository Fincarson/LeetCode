var prev *TreeNode

func inorder(root *TreeNode) bool {
    if root == nil {
        return true
    }
    if !inorder(root.Left) {
        return false
    }
    if prev != nil && root.Val <= prev.Val {
        return false
    }
    prev = root
    return inorder(root.Right)
}

func isValidBST(root *TreeNode) bool {
    prev = nil
    return inorder(root)
}
