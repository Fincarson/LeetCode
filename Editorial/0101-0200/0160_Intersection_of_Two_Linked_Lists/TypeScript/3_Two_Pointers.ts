function getIntersectionNode(headA: ListNode, headB: ListNode): ListNode {
    let pA = headA;
    let pB = headB;
    while (pA !== pB) {
        pA = pA === null ? headB : pA.next;
        pB = pB === null ? headA : pB.next;
    }
    return pA;
    // Note: In the case lists do not intersect, the pointers for A and B
    // will still line up in the 2nd iteration, just that here won't be
    // a common node down the list and both will reach their respective ends
    // at the same time. So pA will be NULL in that case.
}
