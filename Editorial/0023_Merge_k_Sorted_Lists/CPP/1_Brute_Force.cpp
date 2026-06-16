// Definition for singly-linked list.
// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        ListNode head(0);
        ListNode* point = &head;
        for (ListNode* l : lists) {
            while (l) {
                nodes.push_back(l->val);
                l = l->next;
            }
        }
        sort(nodes.begin(), nodes.end());
        for (int x : nodes) {
            point->next = new ListNode(x);
            point = point->next;
        }
        return head.next;
    }
};
