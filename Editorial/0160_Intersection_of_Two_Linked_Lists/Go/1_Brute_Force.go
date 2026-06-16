func getIntersectionNode(headA, headB *ListNode) *ListNode {
    curA := headA
    for curA != nil {
        curB := headB
        for curB != nil {
            if curA == curB {
                return curA
            }
            curB = curB.Next
        }
        curA = curA.Next
    }
    return nil
}
