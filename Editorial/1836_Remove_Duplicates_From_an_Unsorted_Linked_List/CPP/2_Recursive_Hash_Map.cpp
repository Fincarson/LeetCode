class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> frequency;
        countFrequencies(head, frequency);
        return deleteDuplicatesUnsortedHelper(head, frequency);
    }

private:
    // Count the frequency of each value in the list
    void countFrequencies(ListNode* head, unordered_map<int, int>& frequency) {
        ListNode* current = head;
        while (current != nullptr) {
            ++frequency[current->val];
            current = current->next;
        }
    }

    // Recursively delete duplicates based on the frequency map
    ListNode* deleteDuplicatesUnsortedHelper(
        ListNode* head, unordered_map<int, int>& frequency) {
        if (!head) {
            return nullptr;
        }

        // Recursive call for the next node
        ListNode* updatedNextNode =
            deleteDuplicatesUnsortedHelper(head->next, frequency);
        head->next = updatedNextNode;

        // If the current node is a duplicate, return the updated next node
        if (frequency[head->val] > 1) {
            return updatedNextNode;
        }

        // Otherwise, return the current node
        return head;
    }
};
