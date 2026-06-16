func hasCycle(head *ListNode) bool {
    nodesSeen := make(map[*ListNode]bool)
    current := head
    for current != nil {
        if nodesSeen[current] {
            return true
        }
        nodesSeen[current] = true
        current = current.Next
    }
    return false
}
