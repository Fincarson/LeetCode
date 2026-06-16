func swap(a *TreeNode, b *TreeNode) {
    a.Val, b.Val = b.Val, a.Val
}

func recoverTree(root *TreeNode) {
    var x, y, pred, predecessor *TreeNode
    for root != nil {
        if root.Left != nil {
            predecessor = root.Left
            for predecessor.Right != nil && predecessor.Right != root {
                predecessor = predecessor.Right
            }
            if predecessor.Right == nil {
                predecessor.Right = root
                root = root.Left
            } else {
                if pred != nil && root.Val < pred.Val {
                    y = root
                    if x == nil {
                        x = pred
                    }
                }
                pred = root
                predecessor.Right = nil
                root = root.Right
            }
        } else {
            if pred != nil && root.Val < pred.Val {
                y = root
                if x == nil {
                    x = pred
                }
            }
            pred = root
            root = root.Right
        }
    }
    swap(x, y)
}
