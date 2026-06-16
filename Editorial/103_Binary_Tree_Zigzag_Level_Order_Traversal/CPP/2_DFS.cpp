/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<deque<int>> results;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int level) {
            if (level >= results.size()) {
                results.emplace_back(deque<int>(1, node->val));
            } else {
                if (level % 2 == 0)
                    results[level].push_back(node->val);
                else
                    results[level].push_front(node->val);
            }
            if (node->left != nullptr) dfs(node->left, level + 1);
            if (node->right != nullptr) dfs(node->right, level + 1);
        };
        dfs(root, 0);
        vector<vector<int>> final_results;
        for (auto r : results) {
            final_results.push_back(vector<int>{r.begin(), r.end()});
        }
        return final_results;
    }
};
