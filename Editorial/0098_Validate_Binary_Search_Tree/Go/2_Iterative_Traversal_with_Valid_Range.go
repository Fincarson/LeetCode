type TreeCheck struct {
    Node  *TreeNode
    Lower int
    Upper int
}

func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }
    stack := []TreeCheck{
        {
            Node:  root,
            Lower: math.MinInt64,
            Upper: math.MaxInt64,
        },
    }
    for len(stack) > 0 {
        node := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if node.Node.Val <= node.Lower || node.Node.Val >= node.Upper {
            return false
        }
        if node.Node.Right != nil {
            stack = append(stack, TreeCheck{
                Node:  node.Node.Right,
                Lower: node.Node.Val,
                Upper: node.Upper,
            })
        }
        if node.Node.Left != nil {
            stack = append(stack, TreeCheck{
                Node:  node.Node.Left,
                Lower: node.Lower,
                Upper: node.Node.Val,
            })
        }
    }
    return true
}
