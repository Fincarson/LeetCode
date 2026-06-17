class Solution {

    public int[] distanceToCycle(int n, int[][] edges) {
        boolean[] isInCycle = new boolean[n];
        Arrays.fill(isInCycle, true); // 'isInCycle' is initially true for all nodes
        boolean[] visited = new boolean[n];
        int[] degree = new int[n];
        int[] distances = new int[n];
        List<List<Integer>> adjacencyList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        // Build the adjacency list and calculate node degrees
        for (int[] edge : edges) {
            adjacencyList.get(edge[0]).add(edge[1]);
            adjacencyList.get(edge[1]).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        Queue<Integer> nodeQueue = new LinkedList<>();

        // Start by adding all leaf nodes (degree 1) to the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                nodeQueue.add(i);
            }
        }

        // Perform BFS to remove nodes with degree 1, progressively reducing the graph
        while (!nodeQueue.isEmpty()) {
            int currentNode = nodeQueue.poll();
            isInCycle[currentNode] = false; // Mark the node as not in the cycle

            // Update the degree of neighbors and add them to the queue if their degree becomes 1
            for (int neighbor : adjacencyList.get(currentNode)) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    nodeQueue.add(neighbor);
                }
            }
        }

        // Add all cycle nodes to the queue and mark them as visited
        for (int currentNode = 0; currentNode < n; currentNode++) {
            if (isInCycle[currentNode]) {
                nodeQueue.add(currentNode);
                visited[currentNode] = true;
            }
        }

        // BFS to calculate distances from cycle nodes
        int currentDistance = 0;
        while (!nodeQueue.isEmpty()) {
            int queueSize = nodeQueue.size(); // Track number of nodes to process at this distance level
            for (int i = 0; i < queueSize; i++) {
                int currentNode = nodeQueue.poll();
                distances[currentNode] = currentDistance; // Set the distance for the current node

                // Add unvisited neighbors to the queue
                for (int neighbor : adjacencyList.get(currentNode)) {
                    if (visited[neighbor]) continue;
                    nodeQueue.add(neighbor);
                    visited[neighbor] = true;
                }
            }
            currentDistance++; // Increment distance after processing all nodes at the current level
        }

        return distances;
    }
}
