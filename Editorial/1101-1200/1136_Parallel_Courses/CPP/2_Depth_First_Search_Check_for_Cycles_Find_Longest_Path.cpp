class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
        }
        // check if the graph contains a cycle
        vector<int> visited(N + 1, 0);
        for (int node = 1; node < N + 1; node++) {
            // if has cycle, return -1
            if (dfsCheckCycle(node, graph, visited) == -1) {
                return -1;
            }
        }

        // if no cycle, return the longest path
        vector<int> visitedLength(N + 1, 0);
        int maxLength = 1;
        for (int node = 1; node < N + 1; node++) {
            int length = dfsMaxPath(node, graph, visitedLength);
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }

private:
    int dfsCheckCycle(int node, vector<vector<int>>& graph,
                      vector<int>& visited) {
        // return -1 if has a cycle
        // return 1 if does not have any cycle
        if (visited[node] != 0) {
            return visited[node];
        } else {
            // mark as visiting
            visited[node] = -1;
        }
        for (auto& endNode : graph[node]) {
            if (dfsCheckCycle(endNode, graph, visited) == -1) {
                // we meet a cycle!
                return -1;
            }
        }
        // mark as visited
        visited[node] = 1;
        return 1;
    }

    int dfsMaxPath(int node, vector<vector<int>>& graph,
                   vector<int>& visitedLength) {
        // return the longest path (inclusive)
        if (visitedLength[node] != 0) {
            return visitedLength[node];
        }
        int maxLength = 1;
        for (auto& endNode : graph[node]) {
            int length = dfsMaxPath(endNode, graph, visitedLength);
            maxLength = max(length + 1, maxLength);
        }
        // store it
        visitedLength[node] = maxLength;
        return maxLength;
    }
};
