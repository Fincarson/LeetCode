class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<bool> isInCycle(n, true),
            visited(n, false);  // 'isInCycle' is initially true for all nodes
        vector<int> degree(n, 0), distances(n);
        vector<vector<int>> adjacencyList(n, vector<int>(0));

        // Build the adjacency list and calculate node degrees
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> nodeQueue;

        // Start by adding all leaf nodes (degree 1) to the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                nodeQueue.push(i);
            }
        }

        // Perform BFS to remove nodes with degree 1, progressively reducing the
        // graph
        while (!nodeQueue.empty()) {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();
            isInCycle[currentNode] =
                false;  // Mark the node as not in the cycle

            // Update the degree of neighbors and add them to the queue if their
            // degree becomes 1
            for (auto neighbor : adjacencyList[currentNode]) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    nodeQueue.push(neighbor);
                }
            }
        }

        // Add all cycle nodes to the queue and mark them as visited
        for (int currentNode = 0; currentNode < n; currentNode++) {
            if (isInCycle[currentNode]) {
                nodeQueue.push(currentNode);
                visited[currentNode] = true;
            }
        }

        // BFS to calculate distances from cycle nodes
        int currentDistance = 0;
        while (!nodeQueue.empty()) {
            int queueSize = nodeQueue.size();  // Track number of nodes to
                                               // process at this distance level
            for (int i = 0; i < queueSize; i++) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();

                distances[currentNode] =
                    currentDistance;  // Set the distance for the current node

                // Add unvisited neighbors to the queue
                for (auto neighbor : adjacencyList[currentNode]) {
                    if (visited[neighbor]) continue;
                    nodeQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            currentDistance++;  // Increment distance after processing all nodes
                                // at the current level
        }

        return distances;
    }
};
