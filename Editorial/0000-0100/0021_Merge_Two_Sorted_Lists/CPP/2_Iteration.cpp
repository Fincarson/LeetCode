class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead(-1);
        ListNode* prev = &prehead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        // At least one of l1 and l2 can still have nodes at this point, so
        // connect the non-null list to the end of the merged list.
        prev->next = l1 == nullptr ? l2 : l1;
        return prehead.next;
    }
};
