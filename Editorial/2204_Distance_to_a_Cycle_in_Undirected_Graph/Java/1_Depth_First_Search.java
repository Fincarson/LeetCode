class Solution {

    // DFS to detect cycle nodes and mark them in `isInCycle`
    public boolean detectCycleNodes(
        int currentNode,
        List<List<Integer>> adjacencyList,
        boolean[] isInCycle,
        boolean[] visited,
        int[] parent
    ) {
        visited[currentNode] = true; // Mark current node as visited
        for (int neighbor : adjacencyList.get(currentNode)) {
            if (!visited[neighbor]) {
                parent[neighbor] = currentNode; // Set parent for backtracking
                if (
                    detectCycleNodes(
                        neighbor,
                        adjacencyList,
                        isInCycle,
                        visited,
                        parent
                    )
                ) return true; // Return true if cycle detected
            } else if (parent[currentNode] != neighbor) { // Cycle detected
                isInCycle[neighbor] = true; // Mark the start of the cycle
                int tempNode = currentNode;
                // Backtrack to mark all nodes in the cycle
                while (tempNode != neighbor) {
                    isInCycle[tempNode] = true;
                    tempNode = parent[tempNode];
                }
                return true;
            }
        }
        return false; // No cycle found in this path
    }

    // DFS to calculate distances from cycle nodes
    public void calculateDistances(
        int currentNode,
        int currentDistance,
        List<List<Integer>> adjacencyList,
        int[] distances,
        boolean[] visited,
        boolean[] isInCycle
    ) {
        distances[currentNode] = currentDistance; // Set distance for current node
        visited[currentNode] = true; // Mark node as visited
        for (int neighbor : adjacencyList.get(currentNode)) {
            if (visited[neighbor]) continue; // Skip if already visited
            int newDistance = isInCycle[neighbor] ? 0 : currentDistance + 1; // Reset if on cycle
            calculateDistances(
                neighbor,
                newDistance,
                adjacencyList,
                distances,
                visited,
                isInCycle
            );
        }
    }

    public int[] distanceToCycle(int n, int[][] edges) {
        boolean[] isInCycle = new boolean[n];
        boolean[] visited = new boolean[n];
        int[] parent = new int[n];
        int[] distances = new int[n];
        List<List<Integer>> adjacencyList = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        // Build adjacency list for the graph
        for (int[] edge : edges) {
            adjacencyList.get(edge[0]).add(edge[1]);
            adjacencyList.get(edge[1]).add(edge[0]);
        }

        // Detect and mark cycle nodes
        detectCycleNodes(0, adjacencyList, isInCycle, visited, parent);

        // Reset visited array before distance calculation
        Arrays.fill(visited, false);

        // Calculate distances starting from any cycle node
        for (int i = 0; i < n; i++) {
            if (isInCycle[i]) {
                calculateDistances(
                    i,
                    0,
                    adjacencyList,
                    distances,
                    visited,
                    isInCycle
                );
                break; // Only need to start from one cycle node
            }
        }
        return distances;
    }
}
