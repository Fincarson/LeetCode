class Solution {
public:
    ListNode* left = nullptr;
    bool stop = false;
    void recurseAndReverse(ListNode* right, int m, int n) {
        if (n == 1) return;
        right = right->next;
        if (m > 1) this->left = this->left->next;
        recurseAndReverse(right, m - 1, n - 1);
        if (this->left == right || right->next == this->left) stop = true;
        if (!stop) {
            int t = this->left->val;
            this->left->val = right->val;
            right->val = t;
            this->left = this->left->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        this->left = head;
        recurseAndReverse(head, m, n);
        return head;
    }
};
