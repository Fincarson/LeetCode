type item struct {
    node *TreeNode
    sum  int
}

func sumNumbers(root *TreeNode) int {
    if root == nil {
        return 0
    }
    stack := []*item{{root, root.Val}}
    rootToLeaf := 0
    for len(stack) > 0 {
        n := len(stack) - 1
        i := stack[n]
        stack = stack[:n]
        if i.node.Left == nil && i.node.Right == nil {
            rootToLeaf += i.sum
        } else {
            cur := i.sum * 10
            if i.node.Left != nil {
                stack = append(stack, &item{i.node.Left, cur + i.node.Left.Val})
            }
            if i.node.Right != nil {
                stack = append(stack, &item{i.node.Right, cur + i.node.Right.Val})
            }
        }
    }
    return rootToLeaf
}
