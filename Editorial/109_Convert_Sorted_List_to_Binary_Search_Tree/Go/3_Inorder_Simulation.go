/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 *
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var head *ListNode

func findSize(head *ListNode) int {
    ptr := head
    c := 0
    for ptr != nil {
        ptr = ptr.Next
        c += 1
    }
    return c
}

func convertListToBST(l int, r int) *TreeNode {
    if l > r {
        return nil
    }
    mid := (l + r) / 2
    left := convertListToBST(l, mid-1)
    var node *TreeNode
    if head != nil {
        node = &TreeNode{Val: head.Val}
        node.Left = left
        head = head.Next
        node.Right = convertListToBST(mid+1, r)
    }
    return node
}

func sortedListToBST(headParam *ListNode) *TreeNode {
    size := findSize(headParam)
    head = headParam
    return convertListToBST(0, size-1)
}
