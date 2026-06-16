class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step 1: Build a set of values to remove for O(1) membership checks
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Step 2: Skip leading nodes that must be removed (do NOT delete here)
        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            head = head->next;
        }

        // Step 3: If all nodes were removed
        if (head == nullptr) {
            return nullptr;
        }

        // Step 4: Walk the list and unlink nodes whose values are in the set
        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.count(current->next->val) > 0) {
                // Unlink the next node; do not delete it (harness will free)
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
