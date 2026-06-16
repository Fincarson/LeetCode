func detectCycle(head *ListNode) *ListNode {
    // Initialize tortoise and hare pointers
    tortoise, hare := head, head
    // Move tortoise one step and hare two steps
    for hare != nil && hare.Next != nil {
        tortoise = tortoise.Next
        hare = hare.Next.Next
        // Check if the hare meets the tortoise
        if tortoise == hare {
            break
        }
    }
    // Check if there is no cycle
    if hare == nil || hare.Next == nil {
        return nil
    }
    // Reset either the hare pointer to the head
    hare = head
    // Move both pointers one step until they meet again
    for tortoise != hare {
        tortoise = tortoise.Next
        hare = hare.Next
    }
    // Return the node where the cycle begins
    return tortoise
}
