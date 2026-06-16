class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;

        // start building graph
        dfsBuild(root, nullptr, graph);

        vector<int> answer;
        unordered_set<int> visited;

        // start building queue for BFS, starting from target node
        queue<pair<int, int>> bfs_queue;
        bfs_queue.push({target->val, 0});
        visited.insert(target->val);

        while (!bfs_queue.empty()) {
            pair<int, int> current_node = bfs_queue.front();
            bfs_queue.pop();

            int node_val = current_node.first;
            int dist = current_node.second;

            if (dist == k) {
                answer.push_back(node_val);
                continue;
            }
            for (auto& neighbor : graph[node_val]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    bfs_queue.push({neighbor, dist + 1});
                }
            }
        }
        return answer;
    }

private:
    void dfsBuild(TreeNode* cur_node, TreeNode* parent_node,
                  unordered_map<int, vector<int>>& graph) {
        if (cur_node != nullptr && parent_node != nullptr) {
            graph[cur_node->val].push_back(parent_node->val);
            graph[parent_node->val].push_back(cur_node->val);
        }

        if (cur_node != nullptr && cur_node->left != nullptr) {
            dfsBuild(cur_node->left, cur_node, graph);
        }

        if (cur_node != nullptr && cur_node->right != nullptr) {
            dfsBuild(cur_node->right, cur_node, graph);
        }
    }
};
