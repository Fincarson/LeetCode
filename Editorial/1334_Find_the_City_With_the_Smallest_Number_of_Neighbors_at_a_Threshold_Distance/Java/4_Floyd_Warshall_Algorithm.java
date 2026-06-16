class Solution {

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Large value to represent infinity
        int INF = (int) 1e9 + 7;
        // Distance matrix to store shortest paths between all pairs of cities
        int[][] distanceMatrix = new int[n][n];

        // Initialize distance matrix
        for (int i = 0; i < n; i++) {
            Arrays.fill(distanceMatrix[i], INF); // Set all distances to infinity
            distanceMatrix[i][i] = 0; // Distance to itself is zero
        }

        // Populate the distance matrix with initial edge weights
        for (int[] edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            distanceMatrix[start][end] = weight;
            distanceMatrix[end][start] = weight; // For undirected graph
        }

        // Compute shortest paths using Floyd-Warshall algorithm
        floyd(n, distanceMatrix);

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }

    // Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    void floyd(int n, int[][] distanceMatrix) {
        // Update distances for each intermediate city
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update shortest path from i to j through k
                    distanceMatrix[i][j] = Math.min(
                        distanceMatrix[i][j],
                        distanceMatrix[i][k] + distanceMatrix[k][j]
                    );
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n,
        int[][] distanceMatrix,
        int distanceThreshold
    ) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } // Skip self
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
}
