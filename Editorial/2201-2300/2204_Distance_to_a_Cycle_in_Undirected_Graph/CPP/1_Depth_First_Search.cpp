class Solution {
public:
    // DFS to detect cycle nodes and mark them in `isInCycle`
    bool detectCycleNodes(int currentNode, vector<vector<int>> &adjacencyList,
                          vector<bool> &isInCycle, vector<bool> &visited,
                          vector<int> &parent) {
        visited[currentNode] = true;  // Mark current node as visited
        for (auto neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                parent[neighbor] = currentNode;  // Set parent for backtracking
                if (detectCycleNodes(neighbor, adjacencyList, isInCycle,
                                     visited, parent))
                    return true;  // Return true if cycle detected
            } else if (parent[currentNode] != neighbor) {  // Cycle detected
                isInCycle[neighbor] = true;  // Mark the start of the cycle
                int tempNode = currentNode;
                // Backtrack to mark all nodes in the cycle
                while (tempNode != neighbor) {
                    isInCycle[tempNode] = true;
                    tempNode = parent[tempNode];
                }
                return true;
            }
        }
        return false;  // No cycle found in this path
    }

    // DFS to calculate distances from cycle nodes
    void calculateDistances(int currentNode, int currentDistance,
                            vector<vector<int>> &adjacencyList,
                            vector<int> &distances, vector<bool> &visited,
                            vector<bool> &isInCycle) {
        distances[currentNode] =
            currentDistance;          // Set distance for current node
        visited[currentNode] = true;  // Mark node as visited
        for (auto neighbor : adjacencyList[currentNode]) {
            if (visited[neighbor]) continue;  // Skip if already visited
            int newDistance = isInCycle[neighbor]
                                  ? 0
                                  : currentDistance + 1;  // Reset if on cycle
            calculateDistances(neighbor, newDistance, adjacencyList, distances,
                               visited, isInCycle);
        }
    }

    vector<int> distanceToCycle(int n, vector<vector<int>> &edges) {
        vector<bool> isInCycle(n, false), visited(n, false);
        vector<int> parent(n), distances(n);
        vector<vector<int>> adjacencyList(n);

        // Build adjacency list for the graph
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Detect and mark cycle nodes
        detectCycleNodes(0, adjacencyList, isInCycle, visited, parent);

        // Reset visited array before distance calculation
        fill(visited.begin(), visited.end(), false);

        // Calculate distances starting from any cycle node
        for (int i = 0; i < n; i++) {
            if (isInCycle[i]) {
                calculateDistances(i, 0, adjacencyList, distances, visited,
                                   isInCycle);
                break;  // Only need to start from one cycle node
            }
        }
        return distances;
    }
};
