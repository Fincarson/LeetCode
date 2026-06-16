/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddleElement(ListNode* head) {
        // The pointer used to disconnect the left half from the mid node.
        ListNode* prevPtr = nullptr;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        // Iterate until fastPr doesn't reach the end of the linked list.
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        // Handling the case when slowPtr was equal to head.
        if (prevPtr != nullptr) {
            prevPtr->next = nullptr;
        }
        return slowPtr;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // If the head doesn't exist, then the linked list is empty
        if (head == nullptr) {
            return nullptr;
        }
        // Find the middle element for the list.
        ListNode* mid = this->findMiddleElement(head);
        // The mid becomes the root of the BST.
        TreeNode* node = new TreeNode(mid->val);
        // Base case when there is just one element in the linked list
        if (head == mid) {
            return node;
        }
        // Recursively form balanced BSTs using the left and right halves of the
        // original list.
        node->left = this->sortedListToBST(head);
        node->right = this->sortedListToBST(mid->next);
        return node;
    }
};
