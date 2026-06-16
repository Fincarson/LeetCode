/*
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    // Initialize an empty hash set
    nodesSeen := make(map[*ListNode]bool)
    // Start from the head of the linked list
    node := head
    for node != nil {
        // If the current node is in nodesSeen, we have a cycle
        if _, ok := nodesSeen[node]; ok {
            return node
        } else {
            // Add this node to nodesSeen and move to the next node
            nodesSeen[node] = true
            node = node.Next
        }
    }
    // If we reach a null node, there is no cycle
    return nil
}
