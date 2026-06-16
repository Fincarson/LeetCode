// Golang
func minDepth(root *TreeNode) int {
    var dfs func(root *TreeNode) int
    // Define the depth-first search
    dfs = func(root *TreeNode) int {
        if root == nil {
            return 0
        }
        // If only one of child is non-null, then go into that recursion.
        if root.Left == nil {
            return 1 + dfs(root.Right)
        } else if root.Right == nil {
            return 1 + dfs(root.Left)
        }
        // Both children are non-null, hence call for both children.
        leftDepth := dfs(root.Left)
        rightDepth := dfs(root.Right)
        if leftDepth < rightDepth {
            return 1 + leftDepth
        } else {
            return 1 + rightDepth
        }
    }
    return dfs(root)
}
