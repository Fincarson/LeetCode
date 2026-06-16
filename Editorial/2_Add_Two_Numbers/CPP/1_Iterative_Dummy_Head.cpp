class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int total = carry;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            carry = total / 10;
            current->next = new ListNode(total % 10);
            current = current->next;
        }

        return dummy.next;
    }
};
