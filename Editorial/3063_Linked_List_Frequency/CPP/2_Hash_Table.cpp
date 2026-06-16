class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, ListNode*> frequencies;
        ListNode* current = head;
        ListNode* freqHead = nullptr;

        // Process the linked list, storing
        // frequency ListNodes in the hashtable 
        while (current != nullptr) {
            // Increment frequency of existing element
            if (frequencies.find(current->val) != frequencies.end()) {
                ListNode* frequencyNode = frequencies[current->val];
                frequencyNode->val += 1;
            // New element, create hashtable entry with frequency node
            } else {
                ListNode* newFrequencyNode = new ListNode(1, freqHead);
                frequencies[current->val] = newFrequencyNode;
                freqHead = newFrequencyNode;
            }
            current = current->next;
        }
        return freqHead;
    }
};
