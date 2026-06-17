class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Recursively add a parent pointer to each node.
        add_parent(root, nullptr);

        vector<int> answer;
        unordered_set<TreeNode*> visited;
        dfs(target, k, answer, visited);

        return answer;
    }

private:
    unordered_map<TreeNode*, TreeNode*> parent;

    void add_parent(TreeNode* cur, TreeNode* parent) {
        if (cur) {
            this->parent[cur] = parent;
            add_parent(cur->left, cur);
            add_parent(cur->right, cur);
        }
    }

    void dfs(TreeNode* cur, int distance, vector<int>& answer,
             unordered_set<TreeNode*>& visited) {
        if (!cur || visited.count(cur)) return;

        visited.insert(cur);
        if (distance == 0) {
            answer.push_back(cur->val);
            return;
        }

        dfs(parent[cur], distance - 1, answer, visited);
        dfs(cur->left, distance - 1, answer, visited);
        dfs(cur->right, distance - 1, answer, visited);
    }
};
