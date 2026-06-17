struct ListNode* reverseLinkedList(struct ListNode* head, int k) {
    // Reverse k nodes of the given linked list.
    // This function assumes that the list contains
    // at least k nodes.
    struct ListNode* new_head = NULL;
    struct ListNode* ptr = head;
    while (k > 0) {
        // Keep track of the next node to process in the
        // original list
        struct ListNode* next_node = ptr->next;
        // Insert the node pointed to by "ptr"
        // at the beginning of the reversed list
        ptr->next = new_head;
        new_head = ptr;
        // Move on to the next node
        ptr = next_node;
        // Decrement the count of nodes to be reversed by 1
        k--;
    }
    // Return the head of the reversed list
    return new_head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* ptr = head;
    struct ListNode* ktail = NULL;
    // Head of the final, modified linked list
    struct ListNode* new_head = NULL;
    // Keep going until there are nodes in the list
    while (ptr != NULL) {
        int count = 0;
        // Start counting nodes from the head
        ptr = head;
        // Find the head of the next k nodes
        while (count < k && ptr != NULL) {
            ptr = ptr->next;
            count += 1;
        }
        // If we counted k nodes, reverse them
        if (count == k) {
            // Reverse k nodes and get the new head
            struct ListNode* revHead = reverseLinkedList(head, k);
            // new_head is the head of the final linked list
            if (new_head == NULL) new_head = revHead;
            // ktail is the tail of the previous block of
            // reversed k nodes
            if (ktail != NULL) ktail->next = revHead;
            ktail = head;
            head = ptr;
        }
    }
    // attach the final, possibly un-reversed portion
    if (ktail != NULL) ktail->next = head;
    return new_head == NULL ? head : new_head;
}
