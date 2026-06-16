class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
        }

        vector<int> visited(N + 1, 0);
        int maxLength = 1;
        for (int node = 1; node < N + 1; node++) {
            int length = dfs(node, graph, visited);
            // we meet a cycle!
            if (length == -1) {
                return -1;
            }
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }

private:
    int dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        // return the longest path (inclusive)
        if (visited[node] != 0) {
            return visited[node];
        } else {
            // mark as visiting
            visited[node] = -1;
        }
        int maxLength = 1;
        for (auto& endNode : graph[node]) {
            int length = dfs(endNode, graph, visited);
            // we meet a cycle!
            if (length == -1) {
                return -1;
            }
            maxLength = max(length + 1, maxLength);
        }
        // mark as visited
        visited[node] = maxLength;
        return maxLength;
    }
};
