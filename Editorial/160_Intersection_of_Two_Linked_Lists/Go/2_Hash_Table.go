func getIntersectionNode(headA, headB *ListNode) *ListNode {
    nodesInB := make(map[*ListNode]bool)

    for headB != nil {
        nodesInB[headB] = true
        headB = headB.Next
    }

    for headA != nil {
        // if we find the node pointed to by headA,
        // in our map containing nodes of B, then return the node
        if _, exist := nodesInB[headA]; exist {
            return headA
        }
        headA = headA.Next
    }

    return nil
}
