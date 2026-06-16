struct ListNode* deleteDuplicates(struct ListNode* head) {
    // sentinel
    struct ListNode* sentinel =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinel->val = 0;
    sentinel->next = head;
    // predecessor = the last node
    // before the sublist of duplicates
    struct ListNode* pred = sentinel;
    while (head != NULL) {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if (head->next != NULL && head->val == head->next->val) {
            // move till the end of duplicates sublist
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            // Skip all duplicates
            pred->next = head->next;
            // otherwise, move predecessor
        } else {
            pred = pred->next;
        }
        // move forward
        head = head->next;
    }
    return sentinel->next;
}
