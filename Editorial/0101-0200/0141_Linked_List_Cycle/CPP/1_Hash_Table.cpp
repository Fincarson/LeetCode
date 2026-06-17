class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode *> nodesSeen;
        ListNode *current = head;
        while (current != nullptr) {
            if (nodesSeen.find(current) != nodesSeen.end()) {
                return true;
            }
            nodesSeen.insert(current);
            current = current->next;
        }
        return false;
    }
};
