// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
private:
    vector<int> values;
    void mapListToValues(ListNode* head) {
        while (head != nullptr) {
            this->values.push_back(head->val);
            head = head->next;
        }
    }
    TreeNode* convertListToBST(int left, int right) {
        // Invalid case
        if (left > right) {
            return nullptr;
        }
        // Middle element forms the root.
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(this->values[mid]);
        // Base case for when there is only one element left in the array
        if (left == right) {
            return node;
        }
        // Recursively form BST on the two halves
        node->left = this->convertListToBST(left, mid - 1);
        node->right = this->convertListToBST(mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Form an array out of the given linked list and then
        // use the array to form the BST.
        this->mapListToValues(head);
        // Convert the array to
        return this->convertListToBST(0, this->values.size() - 1);
    }
};
