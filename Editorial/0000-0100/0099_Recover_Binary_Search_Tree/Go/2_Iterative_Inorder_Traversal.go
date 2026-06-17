func recoverTree(root *TreeNode) {
    stack := []*TreeNode{}
    var x, y, pred *TreeNode
    for len(stack) > 0 || root != nil {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if pred != nil && root.Val < pred.Val {
            y = root
            if x == nil {
                x = pred
            } else {
                break
            }
        }
        pred = root
        root = root.Right
    }
    x.Val, y.Val = y.Val, x.Val
}
