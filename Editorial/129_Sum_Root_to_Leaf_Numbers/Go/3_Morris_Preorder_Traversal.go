func sumNumbers(root *TreeNode) int {
    root_to_leaf, curr_number, steps := 0, 0, 0
    var predecessor *TreeNode
    for root != nil {
        if root.Left != nil {
            predecessor = root.Left
            steps = 1
            for predecessor.Right != nil && predecessor.Right != root {
                predecessor = predecessor.Right
                steps++
            }
            if predecessor.Right == nil {
                curr_number = curr_number*10 + root.Val
                predecessor.Right = root
                root = root.Left
            } else {
                if predecessor.Left == nil {
                    root_to_leaf += curr_number
                }
                for i := 0; i < steps; i++ {
                    curr_number /= 10
                }
                predecessor.Right = nil
                root = root.Right
            }
        } else {
            curr_number = curr_number*10 + root.Val
            if root.Right == nil {
                root_to_leaf += curr_number
            }
            root = root.Right
        }
    }
    return root_to_leaf
}
