/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    // If the list has no node or has only one node left.
    if head == nil || head.Next == nil {
        return head
    }
    // Nodes to be swapped
    firstNode := head
    secondNode := head.Next
    // Swapping
    firstNode.Next = swapPairs(secondNode.Next)
    secondNode.Next = firstNode
    // Now the head is the second node
    return secondNode
}
