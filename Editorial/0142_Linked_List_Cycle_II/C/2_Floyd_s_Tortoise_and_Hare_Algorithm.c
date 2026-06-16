struct ListNode *detectCycle(struct ListNode *head) {
    // Initialize tortoise and hare pointers
    struct ListNode *tortoise = head;
    struct ListNode *hare = head;
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    // Move tortoise one step and hare two steps
    do {
        tortoise = tortoise->next;
        hare = hare->next->next;
    } while (hare != NULL && hare->next != NULL && tortoise != hare);
    // Check if there is no cycle
    if (hare == NULL || hare->next == NULL) {
        return NULL;
    }
    // Reset the hare pointer to the head
    hare = head;
    // Move both pointers one step until they meet again
    while (tortoise != hare) {
        tortoise = tortoise->next;
        hare = hare->next;
    }
    // Return the node where the cycle begins
    return tortoise;
}
