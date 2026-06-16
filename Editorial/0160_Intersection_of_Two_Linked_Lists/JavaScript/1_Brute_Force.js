function getIntersectionNode(headA, headB) {
    while (headA !== null) {
        let pB = headB;
        while (pB !== null) {
            if (headA === pB) return headA;
            pB = pB.next;
        }
        headA = headA.next;
    }
    return null;
}
