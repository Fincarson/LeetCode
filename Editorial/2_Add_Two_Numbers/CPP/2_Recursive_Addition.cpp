class Solution {
private:
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int total = carry;
        if (l1) {
            total += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            total += l2->val;
            l2 = l2->next;
        }

        ListNode* node = new ListNode(total % 10);
        node->next = add(l1, l2, total / 10);
        return node;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
