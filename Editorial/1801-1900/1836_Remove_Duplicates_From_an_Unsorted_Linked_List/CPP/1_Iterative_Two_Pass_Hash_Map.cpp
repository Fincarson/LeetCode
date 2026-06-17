class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        unordered_map<int, int> frequency;
        ListNode *temp = head, *current = dummy->next, *prev = dummy;

        // Count occurrences of each value in the linked list.
        while (temp) {
            frequency[temp->val]++;
            temp = temp->next;
        }

        // Traverse the list and remove nodes with values that appear more than
        // once.
        while (current) {
            if (frequency[current->val] > 1) {
                // Delete current node from the list
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }
        return dummy->next;
    }
};
