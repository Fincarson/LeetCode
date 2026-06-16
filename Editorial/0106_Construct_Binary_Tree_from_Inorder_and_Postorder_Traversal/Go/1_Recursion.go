func buildTree(inorder []int, postorder []int) *TreeNode {
    idx_map := map[int]int{}
    post_idx := len(postorder) - 1
    var helper func(in_left int, in_right int) *TreeNode
    helper = func(in_left int, in_right int) *TreeNode {
        if in_left > in_right {
            return nil
        }
        root_val := postorder[post_idx]
        root := &TreeNode{Val: root_val}
        index := idx_map[root_val]
        post_idx--
        root.Right = helper(index+1, in_right)
        root.Left = helper(in_left, index-1)
        return root
    }
    for i := 0; i < len(inorder); i++ {
        idx_map[inorder[i]] = i
    }
    return helper(0, len(inorder)-1)
}
