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
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    mid := findMiddleElement(head)
    node := &TreeNode{
        Val: mid.Val,
    }
    if head == mid {
        return node
    }
    node.Left = sortedListToBST(head)
    node.Right = sortedListToBST(mid.Next)
    return node
}

func findMiddleElement(head *ListNode) *ListNode {
    var prevPtr *ListNode = nil
    slowPtr := head
    fastPtr := head
    for fastPtr != nil && fastPtr.Next != nil {
        prevPtr = slowPtr
        slowPtr = slowPtr.Next
        fastPtr = fastPtr.Next.Next
    }
    if prevPtr != nil {
        prevPtr.Next = nil
    }
    return slowPtr
}
