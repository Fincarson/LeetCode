func flatten(root *TreeNode) {
    if root == nil {
        return
    }
    tailNode := new(TreeNode)
    START, END := 1, 2
    stack := [][]interface{}{{root, START}}
    for len(stack) > 0 {
        nodeData := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        node := nodeData[0].(*TreeNode)
        state := nodeData[1].(int)
        if node.Left == nil && node.Right == nil {
            tailNode = node
            continue
        }
        if state == START {
            if node.Left != nil {
                stack = append(stack, []interface{}{node, END})
                stack = append(stack, []interface{}{node.Left, START})
            } else if node.Right != nil {
                stack = append(stack, []interface{}{node.Right, START})
            }
        } else {
            rightNode := node.Right
            if tailNode != nil {
                tailNode.Right = node.Right
                node.Right = node.Left
                node.Left = nil
                rightNode = tailNode.Right
            }
            if rightNode != nil {
                stack = append(stack, []interface{}{rightNode, START})
            }
        }
    }
}
