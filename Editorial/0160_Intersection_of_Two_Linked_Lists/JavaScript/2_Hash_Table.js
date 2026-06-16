var getIntersectionNode = function (headA, headB) {
    let nodesInB = new Set();

    while (headB !== null) {
        nodesInB.add(headB);
        headB = headB.next;
    }

    while (headA !== null) {
        // if we find the node pointed to by headA,
        // in our set containing nodes of B, then return the node
        if (nodesInB.has(headA)) {
            return headA;
        }
        headA = headA.next;
    }

    return null;
};
