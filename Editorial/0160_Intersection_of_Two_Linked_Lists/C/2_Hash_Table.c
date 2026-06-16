typedef struct {
    int val;
    struct ListNode* next;
    UT_hash_handle hh;
} HashTable;

struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    HashTable* setForB = NULL;

    // Creating HashSet for all nodes of list B
    while (tempB != NULL) {
        HashTable* s = (HashTable*)malloc(sizeof(HashTable));
        s->next = tempB;
        HASH_ADD_PTR(setForB, next, s);
        tempB = tempB->next;
    }

    // Iterate through list A. If we find any node of list A in the HashSet of
    // B, then return the node
    while (tempA != NULL) {
        HashTable* s;
        HASH_FIND_PTR(setForB, &(tempA), s);
        if (s) return tempA;
        tempA = tempA->next;
    }

    return NULL;
};
