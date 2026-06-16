/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* head;
int findSize(struct ListNode* head) {
    struct ListNode* ptr = head;
    int c = 0;
    while (ptr != NULL) {
        ptr = ptr->next;
        c += 1;
    }
    return c;
}
struct TreeNode* convertListToBST(int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    struct TreeNode* left = convertListToBST(l, mid - 1);
    if (head == NULL) return NULL;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = head->val;
    node->left = left;
    head = head->next;
    node->right = convertListToBST(mid + 1, r);
    return node;
}
struct TreeNode* sortedListToBST(struct ListNode* h) {
    head = h;
    int size = findSize(head);
    return convertListToBST(0, size - 1);
}
