// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
//
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
int* mapListToValues(struct ListNode* head, int* size) {
    int* values = NULL;
    *size = 0;
    while (head != NULL) {
        values = (int*)realloc(values, (*size + 1) * sizeof(int));
        values[(*size)++] = head->val;
        head = head->next;
    }
    return values;
}
struct TreeNode* convertListToBST(int* values, int left, int right) {
    // Invalid case
    if (left > right) {
        return NULL;
    }
    // Middle element forms the root.
    int mid = (left + right) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = values[mid];
    // Base case for when there is only one element left in the array
    if (left == right) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    // Recursively form BST on the two halves
    node->left = convertListToBST(values, left, mid - 1);
    node->right = convertListToBST(values, mid + 1, right);
    return node;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size;
    int* values = mapListToValues(head, &size);
    return convertListToBST(values, 0, size - 1);
}
