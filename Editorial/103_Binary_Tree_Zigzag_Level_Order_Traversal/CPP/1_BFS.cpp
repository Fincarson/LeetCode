// Definition for a binary tree node.
//  struct TreeNode {
//      int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> result;
        deque<TreeNode*> node_queue;
        node_queue.push_back(root);
        node_queue.push_back(nullptr);  // Delimiter for a single level
        deque<int> level_list;
        bool is_order_left = true;
        while (!node_queue.empty()) {
            TreeNode* temp = node_queue.front();
            node_queue.pop_front();
            if (temp != nullptr) {
                if (is_order_left)
                    level_list.push_back(temp->val);
                else
                    level_list.push_front(temp->val);
                if (temp->left) node_queue.push_back(temp->left);
                if (temp->right) node_queue.push_back(temp->right);
            } else {
                // Add current level to result and prepare for the next level
                result.push_back(
                    vector<int>{level_list.begin(), level_list.end()});
                level_list.clear();
                if (!node_queue.empty()) node_queue.push_back(nullptr);
                is_order_left = !is_order_left;
            }
        }
        return result;
    }
};
