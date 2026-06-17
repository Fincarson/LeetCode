class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> result;
    unordered_set<int> visited;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(root, nullptr);

        visited.insert(target->val);
        dfs(target->val, 0, K);

        return result;
    }

    // Recursively build the undirected graph from the given binary tree.
    void buildGraph(TreeNode* current, TreeNode* parent) {
        if (current != nullptr && parent != nullptr) {
            graph[current->val].push_back(parent->val);
            graph[parent->val].push_back(current->val);
        }
        if (current->left != nullptr) {
            buildGraph(current->left, current);
        }
        if (current->right != nullptr) {
            buildGraph(current->right, current);
        }
    }

    void dfs(int current, int distance, int K) {
        if (distance == K) {
            result.push_back(current);
            return;
        }

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                dfs(neighbor, distance + 1, K);
            }
        }
    }
};
