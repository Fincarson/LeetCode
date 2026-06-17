// Golang
func isSymmetric(root *TreeNode) bool {
    q := []*TreeNode{root, root}
    for len(q) > 0 {
        t1 := q[0]
        t2 := q[1]
        q = q[2:]
        if t1 == nil && t2 == nil {
            continue
        }
        if t1 == nil || t2 == nil {
            return false
        }
        if t1.Val != t2.Val {
            return false
        }
        q = append(q, t1.Left, t2.Right, t1.Right, t2.Left)
    }
    return true
}
