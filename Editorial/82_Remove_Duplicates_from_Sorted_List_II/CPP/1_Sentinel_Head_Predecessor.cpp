class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // sentinel
        ListNode* sentinel = new ListNode(0, head);
        // predecessor = the last node
        // before the sublist of duplicates
        ListNode* pred = sentinel;
        while (head != NULL) {
            // If it's a beginning of duplicates sublist
            // skip all duplicates
            if (head->next != NULL && head->val == head->next->val) {
                // Move till the end of duplicates sublist
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip all duplicates
                pred->next = head->next;
                // otherwise, move predecessor
            } else {
                pred = pred->next;
            }
            // move forward
            head = head->next;
        }
        return sentinel->next;
    }
};
