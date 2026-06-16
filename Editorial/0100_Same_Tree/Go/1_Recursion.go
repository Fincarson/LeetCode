func isSameTree(p *TreeNode, q *TreeNode) bool {
    // p and q are both null
    if p == nil && q == nil {
        return true
    }
    // one of p and q is null
    if (q == nil) || (p == nil) {
        return false
    }
    if p.Val != q.Val {
        return false
    }
    return isSameTree(p.Right, q.Right) &&
        isSameTree(p.Left, q.Left)
}
