class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s,
                        vector<int>& marked) {
        // Initialize distances array with maximum values
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        // Bellman-Ford algorithm: relax edges n-1 times
        for (int iter = 0; iter < n - 1; iter++) {
            for (const auto& edge : edges) {
                int from = edge[0];
                int to = edge[1];
                int weight = edge[2];

                // Relaxation step: if we can improve the path to 'to' via
                // 'from'
                if (dist[from] != INT_MAX && dist[from] + weight < dist[to]) {
                    dist[to] = dist[from] + weight;
                }
            }
        }

        // Find minimum distance to any marked node
        int minDist = INT_MAX;
        for (int node : marked) {
            if (dist[node] < minDist) {
                minDist = dist[node];
            }
        }

        // Return -1 if no path exists, otherwise return the minimum distance
        return minDist == INT_MAX ? -1 : minDist;
    }
};
