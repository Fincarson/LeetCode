func recoverTree(root *TreeNode) {
    var x, y, pred *TreeNode
    findTwoSwapped(root, &x, &y, &pred)
    // Swap x and y values
    x.Val, y.Val = y.Val, x.Val
}

func findTwoSwapped(root *TreeNode, x, y, pred **TreeNode) {
    if root == nil {
        return
    }
    findTwoSwapped(root.Left, x, y, pred)
    if *pred != nil && root.Val < (*pred).Val {
        *y = root
        if *x == nil {
            *x = *pred
        } else {
            return
        }
    }
    *pred = root
    findTwoSwapped(root.Right, x, y, pred)
}
