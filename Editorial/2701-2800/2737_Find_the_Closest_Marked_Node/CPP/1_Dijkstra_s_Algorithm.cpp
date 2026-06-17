class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s,
                        vector<int>& marked) {
        // Convert marked array to set for O(1) lookups
        unordered_set<int> markSet(marked.begin(), marked.end());

        // Build adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        // Initialize distance array with infinity values
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        // Min heap prioritized by distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;
        minHeap.emplace(0, s);

        // Dijkstra's algorithm
        while (!minHeap.empty()) {
            auto [distance, node] = minHeap.top();
            minHeap.pop();

            // Found a marked node, return its distance
            if (markSet.count(node)) {
                return dist[node];
            }

            // Explore neighbors
            for (const auto& [nextNode, weight] : adj[node]) {
                int newDist = distance + weight;

                // If we found a shorter path, update and add to the priority
                // queue
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    minHeap.emplace(newDist, nextNode);
                }
            }
        }

        // No path found to any marked node
        return -1;
    }
};
