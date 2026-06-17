// use uthash.h header for C to have hash (set) functionality
// Definition for ListNode in C:
// typedef struct ListNode {
//     int val;
//     struct ListNode* next;
//     UT_hash_handle hh;
// } ListNode;
typedef struct HashNode {
    struct ListNode* node;
    UT_hash_handle hh;
} HashNode;
struct ListNode* detectCycle(struct ListNode* head) {
    // Initialize an empty hash set
    HashNode* nodesSeen = NULL;
    // Start from the head of the linked list
    struct ListNode* node = head;
    while (node != NULL) {
        // If the current node is in nodesSeen, we have a cycle
        HashNode* s;
        HASH_FIND_PTR(nodesSeen, &node, s);
        if (s != NULL) {
            return s->node;
        } else {
            // Add this node to nodesSeen and move to the next node
            HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
            new_node->node = node;
            HASH_ADD_PTR(nodesSeen, node, new_node);
            node = node->next;
        }
    }
    // If we reach a null node, there is no cycle
    return NULL;
}
