class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1 ? l1 : l2;
        ListNode* current = head;
        ListNode* previous = nullptr;
        int carry = 0;

        while (l1 || l2 || carry) {
            if (!current) {
                current = new ListNode(0);
                previous->next = current;
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

            current->val = total % 10;
            carry = total / 10;
            previous = current;

            if (current->next) {
                current = current->next;
            } else if (l1) {
                current->next = l1;
                current = current->next;
            } else if (l2) {
                current->next = l2;
                current = current->next;
            } else {
                current = nullptr;
            }
        }

        return head;
    }
};
