/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
        return nil
    }
    var res [][]int
    nodeQueue := []*TreeNode{root, nil}
    levelList := []int{}
    isOrderLeft := true
    for len(nodeQueue) > 0 {
        currNode := nodeQueue[0]
        nodeQueue = nodeQueue[1:]
        if currNode != nil {
            if isOrderLeft {
                levelList = append(levelList, currNode.Val)
            } else {
                levelList = append([]int{currNode.Val}, levelList...)
            }
            if currNode.Left != nil {
                nodeQueue = append(nodeQueue, currNode.Left)
            }
            if currNode.Right != nil {
                nodeQueue = append(nodeQueue, currNode.Right)
            }
        } else {
            res = append(res, levelList)
            levelList = []int{}
            if len(nodeQueue) > 0 {
                nodeQueue = append(nodeQueue, nil)
            }
            isOrderLeft = !isOrderLeft
        }
    }
    return res
}
