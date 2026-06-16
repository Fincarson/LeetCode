struct ListNode* addLists(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (!l1 && !l2 && carry == 0) {
        return NULL;
    }

    int total = carry;
    if (l1) {
        total += l1->val;
        l1 = l1->next;
    }

    if (l2) {
        total += l2->val;
        l2 = l2->next;
    }

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = total % 10;
    node->next = addLists(l1, l2, total / 10);
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addLists(l1, l2, 0);
}
