struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    int length = 0;
    struct ListNode* first = head;
    while (first != NULL) {
        length++;
        first = first->next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {
        length--;
        first = first->next;
    }
    first->next = first->next->next;
    return dummy->next;
}
