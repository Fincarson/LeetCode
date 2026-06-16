struct ListNode* FindMiddle(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL) prev->next = NULL;
    return slow;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* mid = FindMiddle(head);
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = mid->val;
    if (head == mid) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    return node;
}
