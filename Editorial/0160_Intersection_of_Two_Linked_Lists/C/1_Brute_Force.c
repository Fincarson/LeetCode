struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
    while (headA != NULL) {
        struct ListNode* pB = headB;
        while (pB != NULL) {
            if (headA == pB) return headA;
            pB = pB->next;
        }
        headA = headA->next;
    }
    return NULL;
}
