class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        const int maxValue = 100000; // Maximum element value 
        vector<int> frequencies(maxValue, 0);
        ListNode* current = head;

        // Find the frequency of each element
        while (current != nullptr) {
            frequencies[current->val - 1]++;
            current = current->next;
        }

        ListNode* freqHead = new ListNode(0);
        current = freqHead;

        // Create a linked list of the frequencies of the elements
        for (int i = 0; i < maxValue; i++) {
            if (frequencies[i] > 0) {
                current->next = new ListNode(frequencies[i]);
                current = current->next;
            }
        }
        return freqHead->next;
    }
};
