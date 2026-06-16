func getIntersectionNode(headA, headB *ListNode) *ListNode {
    pA := headA
    pB := headB
    for pA != pB {
        if pA != nil {
            pA = pA.Next
        } else {
            pA = headB
        }
        if pB != nil {
            pB = pB.Next
        } else {
            pB = headA
        }
    }
    return pA
    // Note: In the case lists do not intersect, the pointers for A and B
    // will still line up in the 2nd iteration, just that here won't be
    // a common node down the list and both will reach their respective ends
    // at the same time. So pA will be NULL in that case.
}
