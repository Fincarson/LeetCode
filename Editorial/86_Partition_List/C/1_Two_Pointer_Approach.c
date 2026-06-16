struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* before_head =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    before_head->next = NULL;
    struct ListNode* before = before_head;
    struct ListNode* after_head =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    after_head->next = NULL;
    struct ListNode* after = after_head;
    while (head != NULL) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;
    before->next = after_head->next;
    return before_head->next;
}
