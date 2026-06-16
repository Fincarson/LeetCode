/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // If the list has no node or has only one node left.
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }
    // Nodes to be swapped
    struct ListNode* firstNode = head;
    struct ListNode* secondNode = head->next;
    // Swapping
    firstNode->next = swapPairs(secondNode->next);
    secondNode->next = firstNode;
    // Now the head is the second node
    return secondNode;
}
