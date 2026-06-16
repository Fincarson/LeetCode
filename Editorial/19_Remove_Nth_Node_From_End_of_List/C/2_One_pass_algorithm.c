/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;
    // Advances first pointer so that the gap between first and second is n
    // nodes apart
    for (int i = 1; i <= n + 1; i++) first = first->next;
    // Move first to the end, maintaining the gap
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy.next;
}
