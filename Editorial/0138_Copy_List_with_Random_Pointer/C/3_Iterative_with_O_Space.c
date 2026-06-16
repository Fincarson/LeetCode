struct Node* nodeConstructor(int val, struct Node* next, struct Node* random) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = next;
    newNode->random = random;
    return newNode;
}
struct Node* copyRandomList(struct Node* head) {
    if (!head) {
        return NULL;
    }
    // Creating a new weaved list of original and copied nodes.
    struct Node* ptr = head;
    while (ptr != NULL) {
        // Cloned node
        struct Node* newNode = nodeConstructor(ptr->val, NULL, NULL);
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
    }
    ptr = head;
    // Now link the random pointers of the new nodes created.
    // Iterate the newly created list and use the original nodes' random
    // pointers, to assign references to random pointers for cloned nodes.
    while (ptr != NULL) {
        ptr->next->random = (ptr->random != NULL) ? ptr->random->next : NULL;
        ptr = ptr->next->next;
    }
    // Unweave the linked list to get back the original linked list and the
    // cloned list. i.e. A->A'->B->B'->C->C' would be broken to A->B->C and
    // A'->B'->C'
    struct Node* ptr_old_list = head;        // A->B->C
    struct Node* ptr_new_list = head->next;  // A'->B'->C'
    struct Node* head_old = head->next;
    while (ptr_old_list != NULL) {
        ptr_old_list->next = ptr_old_list->next->next;
        ptr_new_list->next =
            (ptr_new_list->next != NULL) ? ptr_new_list->next->next : NULL;
        ptr_old_list = ptr_old_list->next;
        ptr_new_list = ptr_new_list->next;
    }
    return head_old;
}
