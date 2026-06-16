/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inorderTraversal(root *TreeNode) []int {
    res := []int{}
    curr := root
    var pre *TreeNode
    for curr != nil {
        if curr.Left == nil {
            res = append(res, curr.Val)
            curr = curr.Right // move to next right node
        } else { // has a left subtree
            pre = curr.Left
            for pre.Right != nil && pre.Right != curr { // find rightmost
                pre = pre.Right
            }
            if pre.Right == nil { // if the rightmost node's right child is nil
                pre.Right = curr // put current after the pre node
                curr = curr.Left // move curr to the top of the new tree
            } else { // the rightmost node's right child is not null
                pre.Right = nil             // restore the tree
                res = append(res, curr.Val) // add current value to the result list
                curr = curr.Right           // move current node to the right
            }
        }
    }
    return res
}
