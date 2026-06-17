func sumNumbers(root *TreeNode) int {
    var preorder func(r *TreeNode, currNumber int)
    rootToLeaf := 0
    preorder = func(r *TreeNode, currNumber int) {
        if r != nil {
            currNumber = currNumber*10 + r.Val
            // if it's a leaf, update root-to-leaf sum
            if r.Left == nil && r.Right == nil {
                rootToLeaf += currNumber
            }
            preorder(r.Left, currNumber)
            preorder(r.Right, currNumber)
        }
    }
    preorder(root, 0)
    return rootToLeaf
}
