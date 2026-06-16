int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int nodes[10000], nodesSize = 0;
    struct ListNode* head;
    struct ListNode* point;
    struct ListNode node = {0, NULL};
    head = &node;
    point = head;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* l = lists[i];
        while (l != NULL) {
            nodes[nodesSize++] = l->val;
            l = l->next;
        }
    }
    qsort(nodes, nodesSize, sizeof(int), compare);
    for (int i = 0; i < nodesSize; i++) {
        struct ListNode* new_node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val = nodes[i];
        new_node->next = NULL;
        point->next = new_node;
        point = point->next;
    }
    return head->next;
}
