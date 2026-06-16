// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
struct ListNode* leftNode;
bool stop;
void recurseAndReverse(struct ListNode* right, int m, int n) {
    // base case. Don't proceed any further
    if (n == 1) {
        return;
    }
    right = right->next;
    if (m > 1) {
        leftNode = leftNode->next;
    }
    recurseAndReverse(right, m - 1, n - 1);
    if (leftNode == right || right->next == leftNode) {
        stop = true;
    }
    if (!stop) {
        int t = leftNode->val;
        leftNode->val = right->val;
        right->val = t;
        leftNode = leftNode->next;
    }
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    leftNode = head;
    stop = false;
    recurseAndReverse(head, m, n);
    return head;
}
