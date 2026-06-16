function getIntersectionNode(
    headA: ListNode | null,
    headB: ListNode | null,
): ListNode | null {
    while (headA !== null) {
        let pB: ListNode | null = headB;
        while (pB !== null) {
            if (headA === pB) return headA;
            pB = pB.next;
        }
        headA = headA.next;
    }
    return null;
}
