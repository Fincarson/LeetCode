/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseLinkedList(struct ListNode* head, int k) {
    struct ListNode* new_head = NULL;
    struct ListNode* ptr = head;
    while (k > 0) {
        struct ListNode* next_node = ptr->next;
        ptr->next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int count = 0;
    struct ListNode* ptr = head;
    while (count < k && ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    if (count == k) {
        struct ListNode* reversedHead = reverseLinkedList(head, k);
        head->next = reverseKGroup(ptr, k);
        return reversedHead;
    }
    return head;
}
