class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s,
                        vector<int>& marked) {
        // Adjacency list representation
        vector<vector<pair<int, int>>> graph(n);

        // Build the graph
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].emplace_back(to, weight);
        }

        // Distance array
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        queue<int> queue;
        queue.push(s);

        // Track nodes in queue
        vector<bool> inQueue(n, false);
        inQueue[s] = true;

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            inQueue[current] = false;

            // Explore neighbors
            for (const auto& [nextNode, weight] : graph[current]) {
                // Relaxation step
                if (dist[nextNode] > dist[current] + weight) {
                    dist[nextNode] = dist[current] + weight;

                    // Add to queue if not already in queue
                    if (!inQueue[nextNode]) {
                        queue.push(nextNode);
                        inQueue[nextNode] = true;
                    }
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = INT_MAX;
        for (int node : marked) {
            minDist = min(minDist, dist[node]);
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};
