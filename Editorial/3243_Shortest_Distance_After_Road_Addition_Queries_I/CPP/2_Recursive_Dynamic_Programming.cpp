class Solution {
public:
    // Recursive function to find the minimum distance from the current node to
    // the destination node (n-1)
    int findMinDistance(vector<vector<int>> &adjList, int n, int currentNode,
                        vector<int> &dp) {
        // We've reached the destination node
        if (currentNode == n - 1) return 0;

        // If this node has already been computed, return the stored value
        if (dp[currentNode] != -1) return dp[currentNode];

        int minDistance = n;

        for (int neighbor : adjList[currentNode]) {
            // Recursively find the minimum distance from the neighbor to the
            // destination
            minDistance =
                min(minDistance, findMinDistance(adjList, n, neighbor, dp) + 1);
        }

        // Store the computed minimum distance in the dp array and return it
        return dp[currentNode] = minDistance;
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> dp(
            n, -1);  // DP array to store minimum distances from each node
        vector<vector<int>> adjList(n, vector<int>(0));

        // Initialize the graph with edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        vector<int> answer;

        // Process each query to add new edges
        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];

            // Add the directed edge from u to v
            adjList[u].push_back(v);

            // Find the minimum distance from the starting node (0) to the
            // destination (n-1)
            answer.push_back(findMinDistance(adjList, n, 0, dp));

            // Clear and resize the dp array
            dp.clear();
            dp.resize(n, -1);
        }

        return answer;  // Return the results for each query
    }
};
