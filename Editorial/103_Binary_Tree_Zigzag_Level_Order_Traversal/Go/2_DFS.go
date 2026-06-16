/* Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    results := [][]int{}
    var dfs func(node *TreeNode, level int)
    dfs = func(node *TreeNode, level int) {
        if level >= len(results) {
            results = append(results, []int{node.Val})
        } else {
            if level%2 == 0 {
                results[level] = append(results[level], node.Val)
            } else {
                results[level] = append([]int{node.Val}, results[level]...)
            }
        }
        if node.Left != nil {
            dfs(node.Left, level+1)
        }
        if node.Right != nil {
            dfs(node.Right, level+1)
        }
    }
    dfs(root, 0)
    return results
}
